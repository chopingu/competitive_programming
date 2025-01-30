#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        for(auto p: points) {
            int x = p[0], y = p[1];
            pq.push({x * x + y * y, x, y});
        }

        vector<vector<int>> ans;
        for(int i = 0; i < k; i++) {
            auto p = pq.top();
            pq.pop();
            ans.push_back({p[1], p[2]});
        }

        return ans;
    }
};
