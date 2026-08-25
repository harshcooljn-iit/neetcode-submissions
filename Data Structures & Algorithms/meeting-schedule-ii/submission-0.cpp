/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& a) {
        map<int,int> mp;
        for (auto& e: a){
            mp[e.start]++;
            mp[e.end]--;
        }
        int ans = 0, cur = 0;
        for (auto& [l,f]: mp){
            cur += f;
            ans = max(ans, cur);
        }
        return ans;
    }
};
