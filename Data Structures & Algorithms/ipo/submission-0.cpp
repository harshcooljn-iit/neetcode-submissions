class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // out of all the projects I can take, i should take the one with max profit
        int n = profits.size();
        vector<pair<int,int> > project;
        project.reserve(n);
        for (int i=0;i<n;i++){
            project.push_back({capital[i], profits[i]});
        }      
        sort(project.begin(),project.end());
        queue<pair<int,int> > q;
        priority_queue<int> pq;
        for (int i=0;i<n;i++){
            q.push(project[i]);
        }
        int taken = 0;
        while (taken < k){
            while (!q.empty() && q.front().first <= w){
                pq.push(q.front().second);
                q.pop();
            }
            if (!pq.empty()){
                w += pq.top();
                pq.pop();
                taken++;
            }
            else{
                break;
            }
        }
        return w;
    }
};