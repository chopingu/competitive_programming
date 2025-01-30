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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.empty()) 
            return true;

        vector<array<int, 2>> inter;
        for(auto a: intervals)
            inter.push_back({a.end, a.start});

        sort(inter.begin(), inter.end());
        for(int i = 0; i < inter.size() - 1; i++) {
            int a1 = inter[i][1], b1 = inter[i][0];
            int a2 = inter[i + 1][1], b2 = inter[i + 1][0];
            if(a2 < b1) 
                return false;
        }

        return true;
    }
};
