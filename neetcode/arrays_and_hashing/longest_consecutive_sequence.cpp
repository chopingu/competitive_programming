#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*
         * DFS solution
        unordered_set<int> nodes;
        for(auto i: nums)
            nodes.insert(i);

        unordered_map<int, int> dist;
        auto dfs = [&](int u, auto&& dfs) -> void {
            if(dist.find(u) != dist.end()) 
                return;

            if(nodes.find(u + 1) == nodes.end()) {
                dist[u] = 1;
                return;
            }
            if(dist.find(u + 1) == dist.end()) 
                dfs(u + 1, dfs);

            dist[u] = dist[u + 1] + 1;
        };

        for(auto i: nums)
            dfs(i, dfs);

        int ans = 0;
        for(auto i: dist)
            ans = max(ans, i.second);

        return ans;
        */

        int ans = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(auto i: nums) {
            if(nums.find(i - 1) != nums.end())
                continue;

            int cnt = 1;
            while(nums.find(i + cnt) != nums.end()) 
                cnt++;

            ans = max(ans, cnt);
        }

        return ans;
    }
};
