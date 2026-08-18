class Solution {
public:
    int helper(int i, int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(amount==0) return 0;
        if(i==coins.size()) return INT_MAX;
        if(dp[i][amount]!=-1) return dp[i][amount];
        if(coins[i]>amount) return dp[i][amount]=helper(i+1,amount,coins,dp);

        int take = helper(i,amount-coins[i],coins,dp);
        if(take!=INT_MAX) take=take+1;
        int leave = helper(i+1,amount,coins,dp);

        return dp[i][amount] = min(take,leave);

    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans = helper(0,amount,coins,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};