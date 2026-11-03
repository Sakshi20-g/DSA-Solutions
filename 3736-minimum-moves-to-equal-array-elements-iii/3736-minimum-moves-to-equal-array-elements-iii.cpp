class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxx = INT_MIN;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            maxx = max(maxx,nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            int x = maxx - nums[i];
            count += x;
        }
        
        return count;

    }
};