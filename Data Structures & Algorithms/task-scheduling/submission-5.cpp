class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        map<char,int> mp;
        for (auto& e: tasks){
            mp[e]++;
        }
        priority_queue<pair<int,char> > pq;
        queue<tuple<int,int,char> > q;
        for (auto& e: mp){
            pq.push({e.second,e.first});
        }
        int time = 1;
        while (!(pq.empty() && q.empty())){
            while (!q.empty()){
                auto [t,f,c] = q.front();
                if (t > time) break;
                pq.push({f,c});
                q.pop();
            }
            if (!pq.empty()){
                auto [f,c] = pq.top();
                pq.pop();
                if (f > 1)
                q.push({time+n+1,f-1,c});
                time++;
            }
            else{
                auto [t,f,c] = q.front();
                time = t;
            }
        }
        return time-1;
    }
};
