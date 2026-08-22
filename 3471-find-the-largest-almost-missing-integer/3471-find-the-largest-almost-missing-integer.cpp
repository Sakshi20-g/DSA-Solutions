class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        // Case 1: When k equals 1, find the largest number that appears exactly once
        if (k == 1) {
            unordered_map<int, int> frequencyMap;
          
            // Count the frequency of each number
            for (int num : nums) {
                ++frequencyMap[num];
            }
          
            int maxUniqueValue = -1;
          
            // Find the maximum value that appears exactly once
            for (const auto& [value, frequency] : frequencyMap) {
                if (frequency == 1) {
                    maxUniqueValue = max(maxUniqueValue, value);
                }
            }
          
            return maxUniqueValue;
        }
      
        int arraySize = nums.size();
      
        // Case 2: When k equals array size, return the maximum element
        if (k == arraySize) {
            return ranges::max(nums);
        }
      
        // Case 3: For other values of k, check if first or last element is unique
        // Lambda function to check if element at given index is unique in the array
        auto getValueIfUnique = [&](int targetIndex) -> int {
            for (int i = 0; i < arraySize; ++i) {
                // If any other element equals the target element, it's not unique
                if (i != targetIndex && nums[i] == nums[targetIndex]) {
                    return -1;
                }
            }
            // Element is unique, return its value
            return nums[targetIndex];
        };
      
        // Return the maximum between the first element (if unique) and last element (if unique)
        return max(getValueIfUnique(0), getValueIfUnique(arraySize - 1));
    }
};
