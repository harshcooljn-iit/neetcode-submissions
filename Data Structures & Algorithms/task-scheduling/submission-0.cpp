class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int,int> > q;
        int time = 0;
        vector<int> a(26);
        for (auto& c: tasks){
            a[c-'A']++;
        }
        for (int i=0;i<26;i++){
            if (a[i]) pq.push(a[i]);
        }
        while (!pq.empty() || !q.empty()){
            if (!pq.empty()){
                int f = pq.top();
                pq.pop();
                time++;
                if (f - 1 > 0)
                q.push({time+n,f-1});
            }
            else time++;
            while (!q.empty() && q.front().first <= time){
                pq.push(q.front().second);
                q.pop();
            }
        }
        return time;
    }
};
