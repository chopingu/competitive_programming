#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = 1e9, ans = 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            int sum = 0;
            for(auto i: piles)
                sum += (i + mid - 1) / mid;

            (sum <= h) ? ans = mid, hi = mid - 1 : lo = mid + 1;
        }

        return ans;
    }
};
