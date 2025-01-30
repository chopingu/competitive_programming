#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int it = 0, ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(mp.find(s[i]) != mp.end() && mp[s[i]] != -1)
                while(it <= mp[s[i]])
                    mp[s[it++]] = -1;

            mp[s[i]] = i;
            ans = max(ans, i - it + 1);
        }

        return ans;
    }
};
