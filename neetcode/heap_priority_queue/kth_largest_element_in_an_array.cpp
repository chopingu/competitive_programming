#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i: nums) {
            pq.push(i);
            if((int)pq.size() == k + 1)
                pq.pop();
        }

        return pq.top();
    }
};
