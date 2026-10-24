class Solution {
public:
    void reversePart(int i,int j,vector<int>& nums){
        while(i<j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
        return;
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<=1) return;
        k = k%n;
        reversePart(0,n-k-1,nums);
        reversePart(n-k,n-1,nums);
        reversePart(0,n-1,nums);
        return;
    }
};