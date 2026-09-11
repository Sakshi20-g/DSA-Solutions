class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> st;

        // Try every possible 3-digit number
        for (int i = 1; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k <= 8; k += 2) {

                    int need[10] = {0};
                    need[i]++;
                    need[j]++;
                    need[k]++;

                    int available[10] = {0};

                    for (int d : digits) {
                        available[d]++;
                    }

                    bool possible = true;

                    for (int d = 0; d <= 9; d++) {
                        if (need[d] > available[d]) {
                            possible = false;
                            break;
                        }
                    }

                    if (possible) {
                        int number = i * 100 + j * 10 + k;
                        st.insert(number);
                    }
                }
            }
        }

        return st.size();
    }
};