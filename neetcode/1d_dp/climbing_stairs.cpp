class Solution {
public:
    int climbStairs(int n) {
        int memo[n + 1]{};
        memo[0] = 1;
        for(int i = 0; i < n; i++) {
            memo[i + 1] += memo[i];
            if(i + 2 <= n) 
                memo[i + 2] += memo[i];
        }

        return memo[n];
    }
};
