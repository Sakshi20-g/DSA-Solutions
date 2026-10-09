class Solution {
public:
    int findMax(vector<int>& piles){
        int mx = INT_MIN;
        for(int i=0;i<piles.size();i++){
            mx = max(mx,piles[i]);
        }
        return mx;
    }
    long long totalHours(vector<int>& v, int hourly){
        long long totalH = 0;
        for(int i=0;i<v.size();i++){
            totalH += ceil((double)v[i]/(double)hourly); 
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = findMax(piles);
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            long long totalH = totalHours(piles,mid);
            if(totalH<=h) hi = mid-1;
            else lo = mid+1;

        }
        return lo;
    }
};