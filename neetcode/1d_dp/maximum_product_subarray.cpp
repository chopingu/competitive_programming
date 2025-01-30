class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mn[n], mx[n];
        mn[0] = nums[0];
        mx[0] = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] <= 0) {
                mx[i] = max(nums[i], mn[i - 1] * nums[i]);
                mn[i] = min(nums[i], mx[i - 1] * nums[i]);
                continue;
            }
            mx[i] = max(nums[i], mx[i - 1] * nums[i]);
            mn[i] = min(nums[i], mn[i - 1] * nums[i]);
        }

        int ans = -1e9;
        for(int i = 0; i < n; i++) 
            ans = max(ans, mx[i]);

        return ans;
    }
};
