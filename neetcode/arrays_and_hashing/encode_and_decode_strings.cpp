#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(auto s: strs) {
            string enc = "";
            string len = to_string(s.size());
            for(int i = 0; i < 3 - len.size(); i++) 
                enc.push_back('0');

            enc += len + s;
            ans += enc;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(int i = 0; i < s.size(); i++) {
            int b = 100;
            int len = 0;
            for(int j = 0; j < 3; j++) {
                len += b * (s[i + j] - '0');
                b /= 10;
            }

            string a = "";
            for(int j = 0; j < len; j++) 
                a.push_back(s[i + 3 + j]);

            ans.push_back(a);

            i += len + 3 - 1;
        }

        return ans;
    }
};
