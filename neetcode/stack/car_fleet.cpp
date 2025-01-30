#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<array<int, 2>> cars;
        for(int i = 0; i < position.size(); i++) 
            cars.push_back({position[i], i});

        sort(cars.begin(), cars.end());
        
        int cnt = 0;
        array<int, 2> last = {target, 1};
        while(!cars.empty()) {
            auto [pos, id] = cars.back();
            cars.pop_back();

            int sp = speed[id];
            if((target - pos) * last[1] > (target - last[0]) * sp) {
                cnt++;
                last = {pos, sp};
            }
        }

        return cnt;
    }
};
