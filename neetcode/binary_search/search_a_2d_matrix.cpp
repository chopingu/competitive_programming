#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0, hi = matrix.size() - 1, row = -1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if(matrix[mid][0] <= target && matrix[mid].back() >= target) {
                row = mid;
                break;
            }

            (matrix[mid][0] >= target) ? hi = mid - 1 : lo = mid + 1;
        }

        if(row == -1)
            return false;

        lo = 0, hi = matrix[row].size() - 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if(matrix[row][mid] == target)
                return true;

            (matrix[row][mid] > target) ? hi = mid - 1 : lo = mid + 1;
        }

        return false;
    }
};
