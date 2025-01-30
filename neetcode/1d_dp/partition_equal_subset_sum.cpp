class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2)
            return false;

        int tar = sum / 2;

        int memo[tar + 1]{};
        memo[0] = 1;
        for(int i = 0; i < n; i++)
            for(int j = tar - nums[i]; j >= 0; j--) 
                memo[j + nums[i]] |= memo[j];

        return memo[tar];
    }
};
