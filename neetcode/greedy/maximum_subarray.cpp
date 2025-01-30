#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int ans = 0, cur = 0;
        for(auto i: nums) {
            cur += i;
            ans = max(ans, cur);
            if(cur < 0)
                cur = 0;
        }

        if(mx < 0)
            return mx;

        return ans;
    }
};
