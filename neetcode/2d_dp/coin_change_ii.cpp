class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int memo[amount + 1]{};
        memo[0] = 1;
        for(int i = 0; i < n; i++) 
            for(int j = 0; j <= amount - coins[i]; j++) 
                memo[j + coins[i]] += memo[j];

        return memo[amount];
    }
};
