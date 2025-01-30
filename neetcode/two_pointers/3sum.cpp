#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<int> s;
        set<vector<int>> sols;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) 
                if(s.find(-nums[i] - nums[j]) != s.end()) {
                    vector<int> tmp({-nums[i] - nums[j], nums[i], nums[j]});
                    sort(tmp.begin(), tmp.end());
                    sols.insert(tmp);
                }

            s.insert(nums[i]);
        }

        vector<vector<int>> ans(sols.begin(), sols.end());
        return ans;
    }
};
