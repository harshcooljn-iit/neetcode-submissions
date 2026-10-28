class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        map<char,int> mp;
        int sum = 0;
        for (auto& e: tasks){
            mp[e]++;
            sum++;
        }
        map<int,int> mp2;
        for (auto& e: mp){
            mp2[e.second]++;
        }
        int f = mp2.rbegin()->second;
        int v = mp2.rbegin()->first;
        int rem = sum - f * v;
        int gaps = (n+2 - f - 1) * (v-1);
        int time = 1 + (v-1) * (n + 1) + f - 1 + max(0,(rem - gaps));
        return time;
    }
};
