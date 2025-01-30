#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot = nums1.size() + nums2.size();
        int left_tot = (tot + 1) / 2;

        int lo = 0, hi = nums1.size();
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int rem = left_tot - mid;

            if(rem < 0) {
                hi = mid - 1;
                continue;
            }
            else if(rem > nums2.size()) {
                lo = mid + 1;
                continue;
            }

            int le1 = (mid) ? nums1[mid - 1] : -1e9;
            int ri1 = (mid != nums1.size()) ? nums1[mid] : 1e9;
            int le2 = (rem) ? nums2[rem - 1] : -1e9;
            int ri2 = (rem < nums2.size()) ? nums2[rem] : 1e9;

            if(le2 <= ri1 && ri2 >= le1) {
                if(tot % 2) 
                    return max(le2, le1);

                return (max(le1, le2) + min(ri1, ri2)) / 2.0;
            }

            (ri2 < le1) ? hi = mid - 1 : lo = mid + 1;
        }

        return -1;
    }
};
