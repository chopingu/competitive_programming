struct val {
    int a = -1;
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        map<array<int, 2>, val> memo;
        auto dp = [&](int id, int cur, auto&& dp) -> int {
            if(id == n) {
                if(cur == target)
                    return 1;

                return 0;
            }

            int &ans = memo[{id, cur}].a;
            if(ans ^ -1)
                return ans;

            return ans = dp(id + 1, cur - nums[id], dp) + dp(id + 1, cur + nums[id], dp);
        };

        return dp(0, 0, dp);
    }
};
