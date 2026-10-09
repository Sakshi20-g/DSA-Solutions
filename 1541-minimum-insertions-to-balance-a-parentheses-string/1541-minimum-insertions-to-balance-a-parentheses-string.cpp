class Solution {
public:
    int minInsertions(string s) {
        int insertionsNeeded = 0;  // Count of characters we need to insert
        int openParentheses = 0;    // Count of unmatched opening parentheses
        int n = s.size();
      
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                // Found an opening parenthesis, increment the counter
                ++openParentheses;
            } else {
                // Found a closing parenthesis, need to check if we have a pair '))'
              
                // Check if the next character is also a closing parenthesis
                if (i < n - 1 && s[i + 1] == ')') {
                    // We have a complete pair '))', skip the next character
                    ++i;
                } else {
                    // We only have a single ')', need to insert another ')'
                    ++insertionsNeeded;
                }
              
                // Now we have a complete '))', check if there's a matching '('
                if (openParentheses == 0) {
                    // No opening parenthesis to match, need to insert a '('
                    ++insertionsNeeded;
                } else {
                    // Match this '))' with an opening parenthesis
                    --openParentheses;
                }
            }
        }
      
        // Each remaining opening parenthesis needs two closing parentheses
        insertionsNeeded += openParentheses * 2;
      
        return insertionsNeeded;
    }
};
