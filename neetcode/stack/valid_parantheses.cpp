#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        auto close = [](char a, char b) -> bool {
            return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
        };

        stack<char> st;
        for(auto ch: s) {
            if(!st.empty() && close(st.top(), ch)) {
                st.pop();
                continue;
            }
            st.push(ch);
        }

        return st.empty();
    }
};
