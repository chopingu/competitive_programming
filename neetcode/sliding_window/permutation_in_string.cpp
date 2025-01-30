#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt1(26);
        for(auto i: s1)
            cnt1[i - 'a']++;

        vector<int> cnt2(26);
        int it = 0;
        for(int i = 0; i < s2.size(); i++) {
            cnt2[s2[i] - 'a']++;

            bool flag = false;
            for(int j = 0; j < 26; j++) 
                flag |= (cnt2[j] > cnt1[j]);

            while(flag) {
                cnt2[s2[it++] - 'a']--;

                flag = false;
                for(int j = 0; j < 26; j++) 
                    flag |= (cnt2[j] > cnt1[j]);
            }

            flag = true;
            for(int j = 0; j < 26; j++) 
                flag &= (cnt2[j] == cnt1[j]);

            if(flag) 
                return true;
        }

        return false;
    }
};
