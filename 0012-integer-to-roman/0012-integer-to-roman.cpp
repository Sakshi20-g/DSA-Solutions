class Solution {
public:
    string intToRoman(int num) {
        // Define Roman numeral symbols and their corresponding values
        // Ordered from largest to smallest, including subtractive notation cases
        vector<string> romanSymbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
      
        string result;
      
        // Iterate through each Roman numeral symbol
        for (int i = 0; i < romanSymbols.size(); ++i) {
            // While the current value can be subtracted from num
            while (num >= values[i]) {
                // Subtract the value and append the corresponding Roman symbol
                num -= values[i];
                result += romanSymbols[i];
            }
        }
      
        return result;
    }
};
