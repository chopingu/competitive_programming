class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        auto dp = [&](int id, auto&& dp) -> int {
            if(id >= n) 
                return 0;

            int &ans = memo[id];
            if(ans != -1)
                return ans;

            return ans = max(dp(id + 1, dp), dp(id + 2, dp) + nums[id]);
        };

        return dp(0, dp);
    }
};
