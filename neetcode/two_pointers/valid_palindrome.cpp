#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string s_parsed = "";
        for(auto ch: s) 
            if(isalnum(ch))
                s_parsed.push_back(tolower(ch));

        for(int i = 0; i < s_parsed.size() / 2; i++)
            if(s_parsed[i] != s_parsed[s_parsed.size() - 1 - i])
                return false;

        return true;
    }
};
