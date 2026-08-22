class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // Calculate the sum of the longest prefix of consecutive sequential integers
        // starting from nums[0]
        int prefixSum = nums[0];
      
        // Iterate through the array to find consecutive sequential elements
        // Stop when we find a non-consecutive element
        for (int i = 1; i < nums.size() && nums[i] == nums[i - 1] + 1; ++i) {
            prefixSum += nums[i];
        }
      
        // Use a bitset to mark which numbers exist in the array
        // Since the problem constraints limit values to be <= 50
        bitset<51> isPresent;
      
        // Mark all numbers that appear in the array
        for (int num : nums) {
            isPresent[num] = 1;
        }
      
        // Find the smallest integer >= prefixSum that is not in the array
        for (int candidate = prefixSum;; ++candidate) {
            // Return if the candidate is out of range or not present in the array
            if (candidate >= 51 || !isPresent[candidate]) {
                return candidate;
            }
        }
    }
};
