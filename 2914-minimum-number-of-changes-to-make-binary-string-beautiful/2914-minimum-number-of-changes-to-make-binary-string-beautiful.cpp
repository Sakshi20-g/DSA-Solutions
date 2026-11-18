class Solution {
public:
    int minChanges(string s) {
        int changeCount = 0;
        int stringLength = s.size();
        for (int i = 1; i < stringLength; i += 2) {
            if (s[i] != s[i - 1]) {
                changeCount++;
            }
        }
      
        return changeCount;
    }
};
