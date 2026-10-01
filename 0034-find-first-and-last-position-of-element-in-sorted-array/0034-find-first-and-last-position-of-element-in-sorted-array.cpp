class Solution {
public:
    
    int findFirst(vector<int>& nums,int target){
        int lo = 0, hi = nums.size()-1;
        int ans = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]==target){
                ans = mid;
                hi = mid-1;
            }
            else if(nums[mid]>target) hi =  mid-1;
            else lo = mid+1;
        }
        return ans;
    }
    int findLast(vector<int>& nums,int target){
        int lo = 0, hi = nums.size()-1;
        int ans = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]==target){
                ans = mid;
                lo = mid+1;
            }
            else if(nums[mid]>target) hi =  mid-1;
            else lo = mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums,target);
        int last = findLast(nums,target);
        return {first, last};
    }
};