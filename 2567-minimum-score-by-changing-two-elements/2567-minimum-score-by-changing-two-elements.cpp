class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int changeTopTwo = nums[n - 3] - nums[0];
        int changeBottomTwo = nums[n - 1] - nums[2];
        int changeOneEach = nums[n - 2] - nums[1];
      
        return min({changeBottomTwo, changeOneEach, changeTopTwo});
    }
};
