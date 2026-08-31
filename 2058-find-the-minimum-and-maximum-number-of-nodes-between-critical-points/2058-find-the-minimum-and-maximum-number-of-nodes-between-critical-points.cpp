/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Initialize result vector with [max_possible_value, 0]
        // result[0] will store minimum distance, result[1] will store maximum distance
        vector<int> result = {INT_MAX, 0};
      
        // Track the index of first and last critical points found
        int firstCriticalIndex = -1;
        int lastCriticalIndex = -1;
      
        // Traverse the linked list with a sliding window of 3 nodes
        // i tracks the index of the middle node in our window
        for (int currentIndex = 0; head->next->next != nullptr; head = head->next, ++currentIndex) {
            // Get values of three consecutive nodes
            int previousValue = head->val;
            int currentValue = head->next->val;
            int nextValue = head->next->next->val;
          
            // Check if current node is a critical point
            // A critical point is either a local minimum or local maximum
            bool isLocalMinimum = (currentValue < previousValue && currentValue < nextValue);
            bool isLocalMaximum = (currentValue > previousValue && currentValue > nextValue);
          
            if (isLocalMinimum || isLocalMaximum) {
                if (lastCriticalIndex == -1) {
                    // This is the first critical point found
                    firstCriticalIndex = currentIndex;
                    lastCriticalIndex = currentIndex;
                } else {
                    // Update minimum distance between consecutive critical points
                    result[0] = min(result[0], currentIndex - lastCriticalIndex);
                  
                    // Update the last critical point index
                    lastCriticalIndex = currentIndex;
                  
                    // Update maximum distance (between first and current critical point)
                    result[1] = max(result[1], lastCriticalIndex - firstCriticalIndex);
                }
            }
        }
      
        // If less than 2 critical points were found, return [-1, -1]
        // This happens when firstCriticalIndex equals lastCriticalIndex (only one critical point)
        // or when no critical points were found (both remain -1)
        if (firstCriticalIndex == lastCriticalIndex) {
            return vector<int>{-1, -1};
        }
      
        return result;
    }
};
