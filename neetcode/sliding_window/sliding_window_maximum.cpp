#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<array<int, 2>> dq;
        for(int i = 0; i < k; i++) {
            while(!dq.empty() && dq.back()[0] <= nums[i])
                dq.pop_back();

            dq.push_back({nums[i], i});
        }

        vector<int> ans({dq.front()[0]});
        for(int i = k; i < nums.size(); i++) {
            while(!dq.empty() && dq.front()[1] <= i - k) 
                dq.pop_front();

            while(!dq.empty() && dq.back()[0] <= nums[i])
                dq.pop_back();

            dq.push_back({nums[i], i});

            ans.push_back(dq.front()[0]);
        }

        return ans;
    }
};
