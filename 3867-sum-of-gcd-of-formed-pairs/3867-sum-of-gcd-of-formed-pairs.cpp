class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixGcd(n);
        int mx = nums[0];
        for(int i=0;i<n;i++){
            mx = max(mx, nums[i]);
            prefixGcd[i] = __gcd(mx,nums[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int left = 0;
        int right = n-1;
        long long result = 0;
        while(left<right){
            result += __gcd(prefixGcd[left],prefixGcd[right]);
            left++;
            right--;
        }
        return result;
    }
};