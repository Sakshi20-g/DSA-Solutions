class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> result;  // Store unique valid results
        int leftToRemove = 0;          // Count of '(' to remove
        int rightToRemove = 0;         // Count of ')' to remove
        int n = s.size();
      
        // First pass: calculate minimum number of parentheses to remove
        for (char& ch : s) {
            if (ch == '(') {
                leftToRemove++;
            } else if (ch == ')') {
                if (leftToRemove > 0) {
                    leftToRemove--;  // Found matching '(' for this ')'
                } else {
                    rightToRemove++;  // Extra ')' that needs to be removed
                }
            }
        }
      
        // DFS function to explore all possible valid combinations
        function<void(int, int, int, int, int, string)> dfs;
        dfs = [&](int index, int leftRem, int rightRem, int leftCount, int rightCount, string current) {
            // Base case: reached end of string
            if (index == n) {
                // Check if we've removed all invalid parentheses
                if (leftRem == 0 && rightRem == 0) {
                    result.insert(current);
                }
                return;
            }
          
            // Pruning conditions:
            // 1. Not enough characters left to remove required parentheses
            // 2. More ')' than '(' at any point (invalid state)
            if (n - index < leftRem + rightRem || leftCount < rightCount) {
                return;
            }
          
            // Option 1: Remove current '(' if we still need to remove left parentheses
            if (s[index] == '(' && leftRem > 0) {
                dfs(index + 1, leftRem - 1, rightRem, leftCount, rightCount, current);
            }
          
            // Option 2: Remove current ')' if we still need to remove right parentheses
            if (s[index] == ')' && rightRem > 0) {
                dfs(index + 1, leftRem, rightRem - 1, leftCount, rightCount, current);
            }
          
            // Option 3: Keep current character
            int addLeft = (s[index] == '(') ? 1 : 0;
            int addRight = (s[index] == ')') ? 1 : 0;
            dfs(index + 1, leftRem, rightRem, leftCount + addLeft, rightCount + addRight, current + s[index]);
        };
      
        // Start DFS from index 0
        dfs(0, leftToRemove, rightToRemove, 0, 0, "");
      
        // Convert set to vector and return
        return vector<string>(result.begin(), result.end());
    }
};
