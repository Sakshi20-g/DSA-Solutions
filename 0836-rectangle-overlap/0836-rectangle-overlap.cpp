class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Extract coordinates for first rectangle
        // rec1[0], rec1[1] = bottom-left corner (x1, y1)
        // rec1[2], rec1[3] = top-right corner (x2, y2)
        int left1 = rec1[0];
        int bottom1 = rec1[1];
        int right1 = rec1[2];
        int top1 = rec1[3];
      
        // Extract coordinates for second rectangle
        // rec2[0], rec2[1] = bottom-left corner (x3, y3)
        // rec2[2], rec2[3] = top-right corner (x4, y4)
        int left2 = rec2[0];
        int bottom2 = rec2[1];
        int right2 = rec2[2];
        int top2 = rec2[3];
      
        // Check for non-overlapping conditions:
        // 1. bottom2 >= top1: rec2 is completely above rec1
        // 2. top2 <= bottom1: rec2 is completely below rec1
        // 3. left2 >= right1: rec2 is completely to the right of rec1
        // 4. right2 <= left1: rec2 is completely to the left of rec1
        // If any of these conditions is true, rectangles don't overlap
        // Therefore, rectangles overlap when NONE of these conditions is true
        return !(bottom2 >= top1 || top2 <= bottom1 || left2 >= right1 || right2 <= left1);
    }
};
