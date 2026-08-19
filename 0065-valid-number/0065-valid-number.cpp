class Solution {
public:
    bool isNumber(string s) {
        bool digit = false;
        bool dot = false;
        bool e = false;
        
        for (int i = 0; i < s.length(); i++) {
            
            if (isdigit(s[i])) {
                digit = true;
            }
            
            else if (s[i] == '.') {
                // Dot cannot appear twice
                // and cannot appear after e
                if (dot || e) {
                    return false;
                }
                dot = true;
            }
            
            else if (s[i] == 'e' || s[i] == 'E') {
                // e cannot appear twice
                // and there must be a digit before e
                if (e || !digit) {
                    return false;
                }
                
                e = true;
                digit = false;  // Now we need a digit after e
            }
            
            else if (s[i] == '+' || s[i] == '-') {
                // Sign is allowed only at the beginning
                // or immediately after e/E
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            }
            
            else {
                return false;
            }
        }
        
        // digit must be true at the end
        return digit;
    }
};