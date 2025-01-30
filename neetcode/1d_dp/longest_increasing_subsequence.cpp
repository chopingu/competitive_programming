class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), k = 0;
        vector<int> memo(n, -1);
        for(int i = 0; i < n; i++) {
            int id = lower_bound(memo.begin(), memo.begin() + k, nums[i]) - memo.begin();
            memo[id] = nums[i];
            k += (k == id);
        }

        return k;
    }
};
