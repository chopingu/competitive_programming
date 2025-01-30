class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int memo[n + 1];
        memset(memo, 0x3f, sizeof memo);
        memo[0] = 0;
        memo[1] = 0;
        for(int i = 0; i < n; i++) {
            memo[i + 1] = min(memo[i + 1], memo[i] + cost[i]);
            if(i + 2 <= n)
                memo[i + 2] = min(memo[i + 2], memo[i] + cost[i]);
        }

        return memo[n];
    }
};
