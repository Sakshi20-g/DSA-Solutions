class Solution {
public:
    bool isHappy(int n) {
        // Use a hash set to track numbers we've seen to detect cycles
        unordered_set<int> visitedNumbers;
      
        // Continue until we either reach 1 (happy number) or find a cycle
        while (n != 1 && !visitedNumbers.count(n)) {
            // Mark current number as visited
            visitedNumbers.insert(n);
          
            // Calculate the sum of squares of digits
            int sumOfSquares = 0;
            while (n > 0) {
                int digit = n % 10;  // Extract the last digit
                sumOfSquares += digit * digit;  // Add square of digit to sum
                n /= 10;  // Remove the last digit
            }
          
            // Update n with the new sum for next iteration
            n = sumOfSquares;
        }
      
        // If we exited because n == 1, it's a happy number
        return n == 1;
    }
};
