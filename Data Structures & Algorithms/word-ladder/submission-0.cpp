class Solution {
public:

    int distance(string a, string b){
        int dist = 0;
        for (int i=0;i<a.size();i++){
            if (a[i]!=b[i]) dist++;
        }
        return dist;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        // Let node 0 = beginword , n+1 = endword
        // we can start a bfs from node 0
        unordered_map<int, string> mp;
        mp[0] = beginWord;
        int end_index = n+1;
        for (int i=0;i<n;i++){
            mp[i+1] = wordList[i];
            if (wordList[i]==endWord){
                end_index = i+1;
            }
        }

        vector<int> dist(n+2,1e9);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            if (node==end_index) break;
            for (int i=1;i<=n;i++){
                if (distance(mp[node],mp[i])==1){
                    cout << node << ' ' << i << endl;
                    if (dist[i] > dist[node] + 1){
                        dist[i] = dist[node] + 1;
                        q.push(i);
                    }
                }
            }
        }

        if (dist[end_index]==1e9){
            dist[end_index] = -1;
        }

        return dist[end_index]+1;
    }
};
