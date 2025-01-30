#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(auto i: nums) 
            if(mp.find(i) == mp.end())
                mp[i] = true;
            else 
                return true;

        return false;
    }
};
