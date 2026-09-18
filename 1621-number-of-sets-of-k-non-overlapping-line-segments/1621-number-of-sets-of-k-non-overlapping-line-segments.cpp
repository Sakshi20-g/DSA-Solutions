class Solution {
public:
    // dp[i][j] = number of ways with i points and j segments where point i is NOT an endpoint
    int dp[1010][1010];
  
    // endingAt[i][j] = number of ways with i points and j segments where point i IS an endpoint
    int endingAt[1010][1010];
  
    const int MOD = 1e9 + 7;

    int numberOfSets(int n, int k) {
        // Initialize DP tables
        memset(dp, 0, sizeof(dp));
        memset(endingAt, 0, sizeof(endingAt));
      
        // Base case: 1 point, 0 segments - one valid way
        dp[1][0] = 1;
      
        // Fill DP table for each point from 2 to n
        for (int points = 2; points <= n; ++points) {
            for (int segments = 0; segments <= k; ++segments) {
                // Case 1: Current point is not an endpoint
                // We can take all configurations from previous point
                dp[points][segments] = (dp[points - 1][segments] + endingAt[points - 1][segments]) % MOD;
              
                // Case 2: Current point is an endpoint of a segment
                // First, extend existing segments that end at previous point
                endingAt[points][segments] = endingAt[points - 1][segments];
              
                if (segments > 0) {
                    // Start a new segment ending at current point
                    // Can start from any previous configuration with (segments - 1) segments
                    endingAt[points][segments] = (endingAt[points][segments] + dp[points - 1][segments - 1]) % MOD;
                  
                    // Or extend a segment that was ending at previous point
                    endingAt[points][segments] = (endingAt[points][segments] + endingAt[points - 1][segments - 1]) % MOD;
                }
            }
        }
      
        // Return total: configurations where last point is or isn't an endpoint
        return (dp[n][k] + endingAt[n][k]) % MOD;
    }
};
