class Solution {
public:
    int minAddToMakeValid(string s) {
        string stack;
      
        for (char c : s) {
        
            if (c == ')' && !stack.empty() && stack.back() == '(') {
                stack.pop_back();
            }
            else {
                stack.push_back(c);
            }
        }
        return stack.size();
    }
};
