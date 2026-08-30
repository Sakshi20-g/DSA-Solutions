class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Initialize write pointer to track position for valid elements
        int writeIndex = 0;
      
        // Iterate through each element in the array
        for (int currentElement : nums) {
            // If current element is not equal to the value to be removed
            if (currentElement != val) {
                // Place it at the write position
                nums[writeIndex] = currentElement;
                // Increment write pointer
                writeIndex++;
            }
        }
      
        // Return the count of elements after removal
        return writeIndex;
    }
};
