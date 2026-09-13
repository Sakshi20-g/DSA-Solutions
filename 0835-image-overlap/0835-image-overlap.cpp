class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        // Map to store the frequency of each translation vector (deltaRow, deltaCol)
        // Key: translation vector, Value: count of overlapping 1s for this translation
        map<pair<int, int>, int> translationCount;
        int maxOverlap = 0;
      
        // Iterate through all cells with value 1 in img1
        for (int row1 = 0; row1 < n; ++row1) {
            for (int col1 = 0; col1 < n; ++col1) {
                if (img1[row1][col1] == 1) {
                    // For each 1 in img1, check all 1s in img2
                    for (int row2 = 0; row2 < n; ++row2) {
                        for (int col2 = 0; col2 < n; ++col2) {
                            if (img2[row2][col2] == 1) {
                                // Calculate the translation vector needed to align
                                // the current 1 in img1 with the current 1 in img2
                                int deltaRow = row1 - row2;
                                int deltaCol = col1 - col2;
                              
                                // Increment count for this translation vector and update max
                                translationCount[{deltaRow, deltaCol}]++;
                                maxOverlap = max(maxOverlap, translationCount[{deltaRow, deltaCol}]);
                            }
                        }
                    }
                }
            }
        }
      
        return maxOverlap;
    }
};
