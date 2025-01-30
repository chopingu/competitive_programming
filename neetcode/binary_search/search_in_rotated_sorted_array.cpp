#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if(target >= nums[0]) {
                if(nums[mid] < nums[0]) {
                    hi = mid - 1;
                    continue;
                }

                if(nums[mid] == target)
                    return mid;

                (nums[mid] > target) ? hi = mid - 1 : lo = mid + 1;
                continue;
            }
            
            if(nums[mid] >= nums[0]) {
                lo = mid + 1;
                continue;
            }

            if(nums[mid] == target) 
                return mid;

            (nums[mid] > target) ? hi = mid - 1 : lo = mid + 1;
        }

        return -1;
    }
};
