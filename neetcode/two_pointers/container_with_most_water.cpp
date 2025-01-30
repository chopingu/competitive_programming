#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        /*
        vector<array<int, 2>> a;
        for(int i = 0; i < heights.size(); i++) 
            a.push_back({heights[i], i});

        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());

        int mn = a[0][1], mx = a[0][1], ans = 0;
        for(int i = 1; i < a.size(); i++) {
            int area = max(abs(mn - a[i][1]) * a[i][0], abs(mx - a[i][1]) * a[i][0]);
            ans = max(ans, area);
            mn = min(mn, a[i][1]);
            mx = max(mx, a[i][1]);
        }

        return ans;
        */
        int le = 0, ri = heights.size() - 1, ans = 0;
        while(le < ri) {
            ans = max(ans, min(heights[le], heights[ri]) * (ri - le));
            (heights[le] <= heights[ri]) ? le++ : ri--;
        }

        return ans;
    }
};
