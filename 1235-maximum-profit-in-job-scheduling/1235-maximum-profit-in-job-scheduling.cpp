class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        
        // Store: {start, end, profit}
        vector<vector<int>> jobs;
        for(int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        // Sort jobs according to ending time
        sort(jobs.begin(), jobs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        // dp[i] = maximum profit using first i jobs
        vector<int> dp(n + 1, 0);
        
        for(int i = 1; i <= n; i++) {
            
            int start = jobs[i - 1][0];
            int currentProfit = jobs[i - 1][2];
            
            // Find previous job whose endTime <= current startTime
            int low = 0;
            int high = i - 2;
            int previous = -1;
            
            while(low <= high) {
                
                int mid = low + (high - low) / 2;
                
                if(jobs[mid][1] <= start) {
                    previous = mid;
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            
            // Take current job
            int take = currentProfit;
            
            if(previous != -1) {
                take += dp[previous + 1];
            }
            
            // Don't take current job
            int notTake = dp[i - 1];
            
            dp[i] = max(take, notTake);
        }
        
        return dp[n];
    }
};
