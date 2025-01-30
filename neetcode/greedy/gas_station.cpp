class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<array<int, 2>> dif(n);
        for(int i = 0; i < n; i++)
            dif[i] = {gas[i] - cost[i], -i};
        
        sort(dif.begin(), dif.end());
        reverse(dif.begin(), dif.end());
        
        int cur = 0;
        for(int i = 0; i < n; i++) {
            cur += dif[i][0];
            if(cur < 0) 
                return -1;
        }

        return -dif[0][1];
    }
};
