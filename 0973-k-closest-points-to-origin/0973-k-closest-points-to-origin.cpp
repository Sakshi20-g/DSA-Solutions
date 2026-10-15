class Solution {
public:
    typedef pair<int,pair<int,int>> piv;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<piv> pq;
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            pq.push({dist,{x,y}});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(pq.size()>0){
            int x = pq.top().second.first;
            int y = pq.top().second.second;

            ans.push_back({x,y});
            pq.pop();
        }
        return ans;
    }
};