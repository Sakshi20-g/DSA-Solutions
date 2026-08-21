class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        for (int i = 2; i <= n; i++) {
            string temp = "";

            int j = 0;

            while (j < ans.length()) {
                int count = 0;
                char ch = ans[j];

                // Count consecutive same characters
                while (j < ans.length() && ans[j] == ch) {
                    count++;
                    j++;
                }

                temp += to_string(count);
                temp += ch;
            }

            ans = temp;
        }

        return ans;
    }
};