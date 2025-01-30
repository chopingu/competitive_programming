#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto i: stones)
            pq.push(i);

        while((int)pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            if(a == b) 
                continue;

            if(a < b)
                swap(a, b);

            pq.push(a - b);
        }

        if(!pq.empty())
            return pq.top();

        return 0;
    }
};
