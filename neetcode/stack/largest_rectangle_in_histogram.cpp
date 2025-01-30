#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> ri(heights.size(), heights.size());
        vector<int> le(heights.size(), -1);
        stack<array<int, 2>> st;
        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && st.top()[0] > heights[i]) 
                ri[st.top()[1]] = i, st.pop();

            st.push({heights[i], i});
        }

        while(!st.empty())
            st.pop();

        for(int i = heights.size() - 1; i >= 0; i--) {
            while(!st.empty() && st.top()[0] > heights[i]) 
                le[st.top()[1]] = i, st.pop();

            st.push({heights[i], i});
        }


        int ans = 0;
        for(int i = 0; i < ri.size(); i++) 
            ans = max(ans, ((ri[i] - 1) - (le[i] + 1) + 1) * heights[i]);

        return ans;
    }
};

