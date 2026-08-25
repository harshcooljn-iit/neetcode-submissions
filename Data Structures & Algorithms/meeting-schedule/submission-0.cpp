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
    bool canAttendMeetings(vector<Interval>& a) {
        sort(a.begin(),a.end(),[](Interval& x, Interval& y){
            if (x.start == y.start) return x.end > y.end;
            return x.start < y.start;
        });
        int n = a.size();
        for (int i=0;i<n-1;i++){
            if (a[i].end > a[i+1].start){
                return false;
            }
        }
        return true;
    }
};
