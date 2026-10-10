using ll = long long;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> differences(n);
        ll totalSum = 0;
        int maxDiff = 0;
        int totalOperations = k1 + k2;

        // Calculate absolute differences and find maximum difference
        for (int i = 0; i < n; ++i) {
            differences[i] = abs(nums1[i] - nums2[i]);
            totalSum += differences[i];
            maxDiff = max(maxDiff, differences[i]);
        }

        // If we can reduce all differences to 0, return 0
        if (totalSum <= totalOperations) {
            return 0;
        }

        // Binary search using the template to find the optimal threshold
        int left = 0;
        int right = maxDiff - 1;
        int firstTrueIndex = maxDiff;  // Default if no smaller threshold is feasible

        while (left <= right) {
            int mid = left + (right - left) / 2;
            ll operationsNeeded = 0;

            // Calculate operations needed to reduce all values to mid
            for (int val : differences) {
                operationsNeeded += max(val - mid, 0);
            }

            if (operationsNeeded <= totalOperations) {
                // Feasible: can achieve this threshold
                firstTrueIndex = mid;
                right = mid - 1;  // Try to find smaller threshold
            } else {
                left = mid + 1;
            }
        }

        int optimalThreshold = firstTrueIndex;

        // Reduce all differences greater than threshold to threshold
        for (int i = 0; i < n; ++i) {
            int reduction = max(0, differences[i] - optimalThreshold);
            totalOperations -= reduction;
            differences[i] = min(differences[i], optimalThreshold);
        }

        // Use remaining operations to further reduce values at threshold
        // This distributes remaining operations evenly
        for (int i = 0; i < n && totalOperations > 0; ++i) {
            if (differences[i] == optimalThreshold) {
                --totalOperations;
                --differences[i];
            }
        }

        // Calculate the sum of squares of final differences
        ll result = 0;
        for (int val : differences) {
            result += 1ll * val * val;
        }

        return result;
    }
};
