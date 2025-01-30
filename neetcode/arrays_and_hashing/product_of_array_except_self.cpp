#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size()), suf(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            pre[i] = (i) ? nums[i] * pre[i - 1] : nums[i];

            int j = nums.size() - 1 - i;
            suf[j] = (i) ? nums[j] * suf[j + 1] : nums[j];
        }

        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int prod = (i) ? pre[i - 1] : 1;
            if(i < nums.size() - 1) 
                prod *= suf[i + 1];

            ans.push_back(prod);
        }

        return ans;
    }
};
