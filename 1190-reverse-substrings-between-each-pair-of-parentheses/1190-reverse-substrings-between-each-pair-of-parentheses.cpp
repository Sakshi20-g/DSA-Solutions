class Solution {
public:
    string reverseParentheses(string s) {
        // Use a string as a stack to store characters
        string stack;
      
        // Process each character in the input string
        for (char& ch : s) {
            if (ch == ')') {
                // When encountering a closing parenthesis, extract and reverse
                string temp;
              
                // Pop characters until we find the matching opening parenthesis
                while (stack.back() != '(') {
                    temp.push_back(stack.back());
                    stack.pop_back();
                }
              
                // Remove the opening parenthesis '('
                stack.pop_back();
              
                // Append the reversed substring back to the stack
                // Note: temp is already reversed due to the popping order
                stack += temp;
            } else {
                // For any other character (including '('), push it onto the stack
                stack.push_back(ch);
            }
        }
      
        // Return the final processed string
        return stack;
    }
};
