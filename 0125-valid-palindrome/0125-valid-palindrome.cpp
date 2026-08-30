class Solution {
public:
    bool isPalindrome(string s) {
        // Initialize two pointers: left starts from beginning, right from end
        int left = 0;
        int right = s.size() - 1;

        // Continue checking while pointers haven't crossed
        while (left < right) {
            // Skip non-alphanumeric character from the left
            if (!isalnum(s[left])) {
                ++left;
            }
            // Skip non-alphanumeric character from the right
            else if (!isalnum(s[right])) {
                --right;
            }
            // Compare characters (case-insensitive)
            // If they don't match, it's not a palindrome
            else if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            // Characters match, move both pointers inward
            else {
                ++left;
                --right;
            }
        }

        // All alphanumeric characters matched successfully
        return true;
    }
};
