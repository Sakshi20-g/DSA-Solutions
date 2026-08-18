class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> height(cols, 0);
        vector<int> left(cols, 0);
        vector<int> right(cols, cols);

        int maxArea = 0;

        for(int i = 0; i < rows; i++) {
            int curLeft = 0, curRight = cols;

            // Update height
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            // Update left boundary
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == '1')
                    left[j] = max(left[j], curLeft);
                else {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }

            // Update right boundary
            for(int j = cols - 1; j >= 0; j--) {
                if(matrix[i][j] == '1')
                    right[j] = min(right[j], curRight);
                else {
                    right[j] = cols;
                    curRight = j;
                }
            }

            // Calculate area
            for(int j = 0; j < cols; j++) {
                int area = (right[j] - left[j]) * height[j];
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
