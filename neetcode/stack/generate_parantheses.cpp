#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        for(int i = 0; i < (1 << (2 * n)); i++) {
            stack<int> st;
            for(int j = 0; j < 2 * n; j++) {
                if(!st.empty() && st.top() == 0 && ((1 << j) & i)) {
                    st.pop();
                    continue;
                }
                st.push(!!((1 << j) & i));
            }

            if(!st.empty()) 
                continue;

            string s = "";
            for(int j = 0; j < 2 * n; j++) 
                if((1 << j) & i)
                    s.push_back(')');
                else 
                    s.push_back('(');

            ans.push_back(s);
        }

        return ans;
    }
};
