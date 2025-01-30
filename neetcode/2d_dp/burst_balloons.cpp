class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> vals({1});
        for(auto i: nums)
            vals.push_back(i);

        vals.push_back(1);
        
        int n = vals.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        auto dp = [&](int le, int ri, auto&& dp) -> int {
            if(ri < le) 
                return 0;

            int &ans = memo[le][ri];
            if(ans != -1)
                return ans;
            
            ans = 0;
            for(int i = le; i <= ri; i++)
                ans = max(ans, dp(le, i - 1, dp) + dp(i + 1, ri, dp) + vals[le - 1] * vals[i] * vals[ri + 1]);

            return ans;
        };

        return dp(1, n - 2, dp);
    }
};
