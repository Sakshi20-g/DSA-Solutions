class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Lambda function to calculate the minimum distance from a point to a range
        // If the point is within the range [minVal, maxVal], distance is 0
        // Otherwise, return the distance to the nearest boundary
        auto calculateDistanceToRange = [](int minVal, int maxVal, int point) -> int {
            if (minVal <= point && point <= maxVal) {
                return 0;  // Point is within the range
            }
            // Point is outside the range, find distance to nearest boundary
            return point < minVal ? minVal - point : point - maxVal;
        };
      
        // Calculate horizontal distance from circle center to rectangle
        // Rectangle's x-range is [x1, x2]
        int horizontalDistance = calculateDistanceToRange(x1, x2, xCenter);
      
        // Calculate vertical distance from circle center to rectangle
        // Rectangle's y-range is [y1, y2]
        int verticalDistance = calculateDistanceToRange(y1, y2, yCenter);
      
        // Check if the squared distance from circle center to rectangle is within radius
        // Using squared values to avoid floating point calculations
        return horizontalDistance * horizontalDistance + verticalDistance * verticalDistance <= radius * radius;
    }
};
