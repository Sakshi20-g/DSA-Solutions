class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // Build a hash map for O(1) lookup of key-value pairs
        unordered_map<string, string> knowledgeMap;
        for (auto& pair : knowledge) {
            knowledgeMap[pair[0]] = pair[1];
        }
      
        string result;
      
        // Iterate through the input string
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                // Found opening bracket, find the matching closing bracket
                int closingBracketPos = s.find(")", i + 1);
              
                // Extract the key between brackets (excluding the brackets)
                string key = s.substr(i + 1, closingBracketPos - i - 1);
              
                // Replace the bracketed expression with its value or "?" if not found
                result += knowledgeMap.count(key) ? knowledgeMap[key] : "?";
              
                // Move index to the closing bracket position to skip processed part
                i = closingBracketPos;
            } else {
                // Regular character, append directly to result
                result += s[i];
            }
        }
      
        return result;
    }
};
