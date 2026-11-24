class Solution {
public:
    int maxLength(vector<int>& nums) {
        int maxElement = 0;
        int overallLcm = 1;
        for (int num : nums) {
            maxElement = max(maxElement, num);
            overallLcm = lcm(overallLcm, num);
        }
        long long maxProduct = (long long)overallLcm * maxElement;
      
        int n = nums.size();
        int maxSubarrayLength = 0;
        for (int i = 0; i < n; ++i) {
            long long product = 1;  
            long long gcdValue = 0; 
            long long lcmValue = 1;  
            for (int j = i; j < n; ++j) {
                product *= nums[j];
                gcdValue = gcd(gcdValue, nums[j]);
                lcmValue = lcm(lcmValue, nums[j]);
              
                if (product == gcdValue * lcmValue) {
                    maxSubarrayLength = max(maxSubarrayLength, j - i + 1);
                }
                if (product > maxProduct) {
                    break;
                }
            }
        }
      
        return maxSubarrayLength;
    }
};
