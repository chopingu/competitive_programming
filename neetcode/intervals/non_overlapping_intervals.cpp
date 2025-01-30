class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<array<int, 2>> inters;
        for(auto a: intervals)
            inters.push_back({a[1], a[0]});

        int ans = 0;
        sort(inters.begin(), inters.end());
        for(int i = 0; i < inters.size(); i++) {
            int a = inters[i][1], b = inters[i][0];
            int id = i + 1;
            while(id < inters.size() && inters[id][1] < b) 
                ans++, id++;

            i = id - 1;
        }

        return ans;
    }
};
