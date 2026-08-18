class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num : nums) freq[num]++;
        for(int num : nums){
            if(num%2==0 && freq[num]==1) return num;
        }
        return -1;
    }
};