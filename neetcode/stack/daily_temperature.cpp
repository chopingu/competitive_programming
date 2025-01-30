#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<array<int, 2>> st;
        for(int i = 0; i < temperatures.size(); i++) {
            while(!st.empty() && st.top()[0] < temperatures[i])
                ans[st.top()[1]] = i - st.top()[1], st.pop();

            st.push({temperatures[i], i});
        }

        return ans;
    }
};
