class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        // Recursively expand the expression and store results in a set
        expandExpression(expression);
      
        // Convert set to vector and return (set automatically sorts and removes duplicates)
        return vector<string>(resultSet.begin(), resultSet.end());
    }

private:
    set<string> resultSet;  // Store unique expanded strings in sorted order

    void expandExpression(string expression) {
        // Find the first closing brace in the expression
        int closeBracePos = expression.find_first_of('}');
      
        // Base case: no more braces to expand, add the final string to result set
        if (closeBracePos == string::npos) {
            resultSet.insert(expression);
            return;
        }
      
        // Find the matching opening brace for the first closing brace
        // Search backwards from the closing brace position
        int openBracePos = expression.rfind('{', closeBracePos);
      
        // Extract three parts of the expression:
        // 1. prefix: everything before the opening brace
        string prefix = expression.substr(0, openBracePos);
      
        // 2. suffix: everything after the closing brace
        string suffix = expression.substr(closeBracePos + 1);
      
        // 3. options: content between the braces (comma-separated values)
        string bracedContent = expression.substr(openBracePos + 1, closeBracePos - openBracePos - 1);
      
        // Parse comma-separated options within the braces
        stringstream optionStream(bracedContent);
        string option;
      
        // For each option, recursively expand the expression
        while (getline(optionStream, option, ',')) {
            // Combine prefix + current option + suffix and recursively expand
            expandExpression(prefix + option + suffix);
        }
    }
};
