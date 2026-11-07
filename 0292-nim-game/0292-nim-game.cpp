class Solution {
public:
    bool canWinNim(int n) {
        // Current player wins if n is not divisible by 4
        return n % 4 != 0;
    }
};
