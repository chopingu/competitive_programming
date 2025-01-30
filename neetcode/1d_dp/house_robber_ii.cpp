class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(2, -1));
        auto dp = [&](int id, int flag, auto&& dp) -> int {
            if(id >= n) 
                return 0;

            int &ans = memo[id][flag];
            if(ans != -1)
                return ans;

            ans = dp(id + 1, flag, dp);
            if(!flag || id != n - 1) 
                ans = max(ans, dp(id + 2, flag | !id, dp) + nums[id]); 

            return ans;
        };

        return dp(0, 0, dp);
    }
};
