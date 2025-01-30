#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(auto i: nums) 
            cnt[i]++;

        vector<array<int, 2>> tmp;
        for(auto i: cnt)
            tmp.push_back({-i.second, i.first});

        sort(tmp.begin(), tmp.end());
        vector<int> ans;
        for(int i = 0; i < k; i++) 
            ans.push_back(tmp[i][1]);

        return ans;
    }
};
