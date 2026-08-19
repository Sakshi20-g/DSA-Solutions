class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }
        //sort task on the basis of enqueue
        sort(tasks.begin(),tasks.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        long long timer = tasks[0][0];
        int i=0;
        while(i<n || !pq.empty()){
            //put all task into minHeap whose enqueue time is less than or equal to current enqueue time
            while(i<n && timer>=tasks[i][0]){
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            //if minHeap is empty
            if(pq.empty()) timer = tasks[i][0];
            //not empty
            else{
                ans.push_back(pq.top().second);
                timer+=pq.top().first;
                pq.pop();
            }
        }
        return ans;
    }
};