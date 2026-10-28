class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> res;
        res.reserve(tasks.size());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minheap;
        queue<tuple<int,int,int> > q;
        for (int i=0;i<tasks.size();i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        for (int i=0;i<tasks.size();i++){
            int time = tasks[i][0], burst = tasks[i][1], id=tasks[i][2];
            q.push({time, burst, id});
        }
        int time = 1;
        while (!(minheap.empty() && q.empty())){
            while (!q.empty()){
                auto [t, b, i] = q.front();
                if (t > time) break;
                q.pop();
                minheap.emplace(b,i);
            }
            if (!minheap.empty()){
                auto [b,i] = minheap.top();
                time += b;
                minheap.pop();
                res.push_back(i);
            }
            else{
                auto [t,b,i] = q.front();
                time = t; // jump forward to next task
            }
        }
        return res;
    }
};