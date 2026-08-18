class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        vector<int> sum;
        int limit = cbrt(n);
        for(int a=1;a<=limit;a++){
            for(int b=a;b<=limit;b++){
                long long val = 1LL*a*a*a + 1LL*b*b*b;
                if(val>n) break;
                sum.push_back(val);
            }
        }

        sort(sum.begin(),sum.end());
        vector<int> ans;
        for(int i=0;i<sum.size();){
            int j=i;
            while(j<sum.size() && sum[j]==sum[i]) j++;
            if(j-i>=2) ans.push_back(sum[i]);
            i=j;
        }
        return ans;
    }
};