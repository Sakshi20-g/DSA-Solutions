class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char, int> freq;
        for(char c : s) freq[c]++;
        unordered_set<char> visited;
        int ans = 0;
        for(auto &it : freq){
            char c = it.first;
            if(visited.count(c)) continue;
            char mirror;
            if(isdigit(c)) mirror = '0'+('9'-c);
            else mirror = 'a'+('z'-c);
            int f1 = freq[c];
            int f2 = freq.count(mirror) ? freq[mirror] : 0;
            ans += abs(f1-f2);

            visited.insert(c);
            visited.insert(mirror);
        }
        return ans;
    }
};