#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) : k(k) {
        for(auto i: nums)
            pq.push(i);

        while(pq.size() > k)
            pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        if((int)pq.size() == k + 1) 
            pq.pop();
        
        return pq.top();
    }
};
