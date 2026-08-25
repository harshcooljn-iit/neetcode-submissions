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
        wordList.push_back(beginWord);
        unordered_map<string,int> mp;
        for (int i=0;i<n;i++){
            mp[wordList[i]] = i;
        }
        if (mp.find(endWord)==mp.end()){
            return 0;
        }

        vector<int> dist(n+1,1e9);
        queue<int> q;
        q.push(n);
        dist[n] = 0;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            if (wordList[node]==endWord) break;
            for (int i=0;i<wordList[node].size();i++){
                for (int j=0;j<26;j++){
                    if (j != (wordList[node][i]-'a')){
                        string next = wordList[node];
                        next[i] = 'a' + j;
                        if (mp.find(next)!=mp.end()){
                            if (dist[mp[next]] > dist[node] + 1){
                                dist[mp[next]] = dist[node] + 1;
                                q.push(mp[next]);
                            }
                        }
                    }
                }
            }
        }

        if (dist[mp[endWord]]==1e9){
            dist[mp[endWord]] = -1;
        }

        return dist[mp[endWord]]+1;
        
    }
};
