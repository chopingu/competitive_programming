class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2, -1));
        auto dp = [&](int id, int flag, auto&& dp) -> int {
            if(id >= n)
                return 0;

            int &ans = memo[id][flag];
            if(ans ^ -1) 
                return ans;

            ans = -1e9;
            if(!flag) {
                ans = max(ans, dp(id + 1, 1, dp) - prices[id]);
                ans = max(ans, dp(id + 1, 0, dp));
            }
            else {
                ans = max(ans, dp(id + 2, 0, dp) + prices[id]);
                ans = max(ans, dp(id + 1, 1, dp));
            }

            return ans;
        };

        return dp(0, 0, dp);
    }
};
