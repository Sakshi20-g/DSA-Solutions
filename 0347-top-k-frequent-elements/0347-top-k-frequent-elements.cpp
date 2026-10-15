class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp; 
        //map pair is ele,freq
        for(int ele : nums){
            mp[ele]++;
        }

        //minheap
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        //travel in hasmap
        for(auto x : mp){
            int ele = x.first;
            int freq = x.second;
            pq.push({freq,ele});
            if(pq.size()>k) pq.pop();
        }

        vector<int> ans;
        while(pq.size()>0){
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        return ans;
    }
};