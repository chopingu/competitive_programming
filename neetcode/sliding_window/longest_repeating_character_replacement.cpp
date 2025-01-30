#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26);
        int it = 0, ans = 0;
        for(int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'A']++;
            int mx = *max_element(cnt.begin(), cnt.end());
            while(i - it + 1 - mx > k) {
                cnt[s[it++] - 'A']--;
                mx = *max_element(cnt.begin(), cnt.end());
            }

            ans = max(ans, i - it + 1);
        }

        return ans;
    }
};
