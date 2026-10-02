class Solution {
public:
    int findMin(vector<int>& nums) {
        int n =  nums.size();
        int lo = 0, hi = n-1;
        int ans = INT_MAX;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            //left part sorted
            if(nums[lo]<=nums[mid]){
                ans = min(nums[lo],ans);
                //eliminate left part
                lo = mid+1;
            }
            //right part sorted
            else{
                ans = min(nums[mid],ans);
                //eliminate the right part
                hi = mid-1;
            }
        }
        return ans;
    }
};