class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]==target) return true;

            //duplicates creates ambiguity
            if(nums[lo]==nums[mid] && nums[mid]==nums[hi]){
                //reduce the search space
                lo++;
                hi--;
                continue;
            }

            //left part sorted
            if(nums[lo]<=nums[mid]){
                if(nums[lo]<=target && target<=nums[mid]){
                    hi = mid-1;
                }
                else lo = mid+1;
            }

            //right part sorted
            if(nums[mid]<=nums[hi]){
                if(nums[mid]<=target && target<=nums[hi]){
                    
                    lo = mid+1;
                }
                else hi = mid-1;
            }
        }
        return false;
    }
};