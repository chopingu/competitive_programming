#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, int>> sorted;
        for(int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            sorted.emplace_back(s, i);
        }

        sort(sorted.begin(), sorted.end());

        vector<vector<string>> ans;
        vector<string> bucket({strs[sorted[0].second]});
        for(int i = 1; i < sorted.size(); i++) {
            if(sorted[i].first != sorted[i - 1].first) {
                ans.push_back(bucket);
                bucket.clear();
            }
            bucket.push_back(strs[sorted[i].second]);
        }
        ans.push_back(bucket);

        return ans;
    }
};
