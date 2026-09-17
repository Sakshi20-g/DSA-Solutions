class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        // Map to store cumulative sum -> index mapping
        // Key: cumulative sum, Value: index (1-based)
        unordered_map<int, int> prefixSumToIndex;
        prefixSumToIndex[0] = 0;  // Initialize with sum 0 at index 0

        int cumulativeSum = 0;
        int n = arr.size();

        // minLength[i] stores the minimum length of a valid subarray
        // ending at or before index i (1-based indexing)
        int minLength[n + 1];
        const int INF = 1 << 30;  // Large value representing infinity
        minLength[0] = INF;  // No valid subarray before index 0

        int result = INF;

        // Iterate through the array with 1-based indexing
        for (int i = 1; i <= n; ++i) {
            int currentValue = arr[i - 1];  // Convert to 0-based array index
            cumulativeSum += currentValue;

            // Initialize current minimum length with previous minimum
            minLength[i] = minLength[i - 1];

            // Check if there exists a subarray ending at current position with sum = target
            // We need: cumulativeSum - previousSum = target
            // So: previousSum = cumulativeSum - target
            if (prefixSumToIndex.count(cumulativeSum - target)) {
                int startIndex = prefixSumToIndex[cumulativeSum - target];
                int currentSubarrayLength = i - startIndex;

                // Update minimum length of valid subarray ending at or before index i
                minLength[i] = min(minLength[i], currentSubarrayLength);

                // Try to form two non-overlapping subarrays:
                // 1. Best subarray ending at or before startIndex
                // 2. Current subarray from startIndex+1 to i
                result = min(result, minLength[startIndex] + currentSubarrayLength);
            }

            // Store current cumulative sum and its index
            prefixSumToIndex[cumulativeSum] = i;
        }

        // If no valid pair of subarrays found, return -1
        return result > n ? -1 : result;
    }
};
