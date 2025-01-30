#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int lo = 0, hi = nums.size() - 1, ans = 0;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            (nums[mid] < nums[0]) ? ans = mid, hi = mid - 1 : lo = mid + 1;
        }

        return nums[ans];
    }
};
