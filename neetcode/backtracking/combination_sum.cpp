class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        vector<vector<int>> ans;
        auto rec = [&](int id, int rem_target, auto&& rec) -> void {
            if(rem_target < 0)
                return;

            if(!rem_target) {
                ans.push_back(cur);
                return;
            }

            if(id == (int)nums.size()) 
                return;

            cur.push_back(nums[id]);
            rec(id, rem_target - nums[id], rec);
            cur.pop_back();

            rec(id + 1, rem_target, rec);
        };

        rec(0, target, rec);

        return ans;
    }
};
