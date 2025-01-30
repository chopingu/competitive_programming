#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        auto ext = [&]() -> array<int, 2> {
            int ri = stoi(st.top());
            st.pop();
            int le = stoi(st.top());
            st.pop();
            return {le, ri};
        };
        for(auto s: tokens) {
            if(s == "+") {
                auto [le, ri] = ext();
                st.push(to_string(le + ri));
            }
            else if(s == "-") {
                auto [le, ri] = ext();
                st.push(to_string(le - ri));
            }
            else if(s == "*") {
                auto [le, ri] = ext();
                st.push(to_string(le * ri));
            }
            else if(s == "/") {
                auto [le, ri] = ext();
                st.push(to_string(le / ri));
            }
            else 
                st.push(s);
        }

        return stoi(st.top());
    }
};
