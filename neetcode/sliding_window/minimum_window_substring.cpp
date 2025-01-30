#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        auto index = [](char ch) -> int {
            if(tolower(ch) != ch)
                return (ch - 'A' + 26);
            
            return ch - 'a';
        };

        vector<int> cnt1(52);
        for(auto ch: t)
            cnt1[index(ch)]++;

        vector<int> cnt2(52);
        int it = 0, id = 0, ans = 1e5;
        for(int i = 0; i < s.size(); i++) {
            bool flag = true;
            for(int j = 0; j < 52; j++) 
                flag &= (cnt2[j] >= cnt1[j]);

            while(!flag && it < s.size()) {
                cnt2[index(s[it++])]++;

                flag = true;
                for(int j = 0; j < 52; j++) 
                    flag &= (cnt2[j] >= cnt1[j]);
            }

            if(!flag) 
                break;

            if(it - i < ans) {
                ans = it - i;
                id = i;
            }

            cnt2[index(s[i])]--;
        }

        if(ans == 1e5)
            return "";

        return s.substr(id, ans);
    }
};
