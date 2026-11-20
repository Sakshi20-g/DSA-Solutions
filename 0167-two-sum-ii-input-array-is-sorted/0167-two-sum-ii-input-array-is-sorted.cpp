class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0; i < n - 1; ++i) {
            int complement = target - numbers[i];
            int left = i + 1;
            int right = n - 1;
            int firstTrueIndex = -1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] >= complement) {
                    firstTrueIndex = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            if (firstTrueIndex != -1 && numbers[firstTrueIndex] == complement) {
                return {i + 1, firstTrueIndex + 1};
            }
        }
        return {};
    }
};
