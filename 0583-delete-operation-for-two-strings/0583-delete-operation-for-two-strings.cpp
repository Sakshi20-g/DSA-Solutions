class Solution {
public:
    int longestCommonSubsequence(string a, string b){
        int m = a.size(), n = b.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
        int lcs = longestCommonSubsequence(word1,word2);
        return word1.size() - lcs + word2.size() - lcs;
    }
};