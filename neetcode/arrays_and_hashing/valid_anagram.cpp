#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt_s(26), cnt_t(26);

        if(s.size() != t.size()) 
            return false;

        for(int i = 0; i < s.size(); i++)
            cnt_s[s[i] - 'a']++, cnt_t[t[i] - 'a']++;

        for(int i = 0; i < 26; i++) 
            if(cnt_s[i] != cnt_t[i]) 
                return false;

        return true;
    }
};
