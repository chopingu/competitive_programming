#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int le = 0, ri = height.size() - 1;
        int ans = 0;
        while(le < ri) {
            if(height[le] <= height[ri]) {
                int it = le + 1;
                while(height[it] < height[le])
                    ans += height[le] - height[it++];

                le = it;
                continue;
            }
            int it = ri - 1;
            while(height[it] < height[ri])
                ans += height[ri] - height[it--];

            ri = it;
        }

        return ans;
    }
};
