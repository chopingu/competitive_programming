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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<array<int, 2>> t;
        for(auto a: intervals) {
            t.push_back({a.start, 1});
            t.push_back({a.end, -1});
        }
        sort(t.begin(), t.end());

        int ans = 0, cnt = 0;
        for(auto a: t) 
            cnt += a[1], ans = max(ans, cnt);

        return ans;
    }
};
