class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;

        // Split s into words
        stringstream ss(s);

        while (ss >> word) {
            words.push_back(word);
        }

        // Number of pattern characters and words must be same
        if (pattern.size() != words.size()) {
            return false;
        }

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string w = words[i];

            // Check character -> word mapping
            if (mp1.count(ch) && mp1[ch] != w) {
                return false;
            }

            // Check word -> character mapping
            if (mp2.count(w) && mp2[w] != ch) {
                return false;
            }

            mp1[ch] = w;
            mp2[w] = ch;
        }

        return true;
    }
};