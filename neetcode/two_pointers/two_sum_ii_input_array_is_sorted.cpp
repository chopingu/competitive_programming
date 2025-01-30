#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int id = numbers.size() - 1;
        for(int i = 0; i < numbers.size(); i++) {
            while(numbers[i] + numbers[id] > target)
                id--;

            if(numbers[i] + numbers[id] == target)
                return {i + 1, id + 1};
        }

        return {};
    }
};
