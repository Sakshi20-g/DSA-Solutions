class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
      
        // Early termination: if lengths don't match, s3 cannot be formed
        if (len1 + len2 != s3.size()) {
            return false;
        }
      
        // Memoization table: -1 = unvisited, 0 = false, 1 = true
        // memo[i][j] represents whether s3[i+j:] can be formed by interleaving s1[i:] and s2[j:]
        vector<vector<int>> memo(len1 + 1, vector<int>(len2 + 1, -1));
      
        // Recursive function to check if interleaving is possible
        function<bool(int, int)> canInterleave = [&](int idx1, int idx2) -> bool {
            // Base case: both strings are fully consumed
            if (idx1 >= len1 && idx2 >= len2) {
                return true;
            }
          
            // Return memoized result if already computed
            if (memo[idx1][idx2] != -1) {
                return memo[idx1][idx2] == 1;
            }
          
            // Initialize current state as false
            memo[idx1][idx2] = 0;
          
            // Current position in s3
            int idx3 = idx1 + idx2;
          
            // Try taking character from s1 if possible
            if (idx1 < len1 && s1[idx1] == s3[idx3]) {
                if (canInterleave(idx1 + 1, idx2)) {
                    memo[idx1][idx2] = 1;
                    return true;
                }
            }
          
            // Try taking character from s2 if possible
            if (idx2 < len2 && s2[idx2] == s3[idx3]) {
                if (canInterleave(idx1, idx2 + 1)) {
                    memo[idx1][idx2] = 1;
                    return true;
                }
            }
          
            // Return the result (will be false if neither option worked)
            return memo[idx1][idx2] == 1;
        };
      
        // Start recursion from the beginning of both strings
        return canInterleave(0, 0);
    }
};
