class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int memo[amount + 1];
        memset(memo, 0x3f, sizeof memo);
        memo[0] = 0;
        for(int i = 0; i < n; i++) 
            for(int j = 0; j <= amount; j++) 
                if(j + coins[i] <= amount && j + coins[i] >= 0) 
                    memo[j + coins[i]] = min(memo[j + coins[i]], memo[j] + 1);

        return (memo[amount] > 1e9) ? -1 : memo[amount];
    }
};
