class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int, int> cnt;
        for(auto i: candidates)
            cnt[i]++;

        vector<int> unq;
        for(auto i: cnt)
            unq.push_back(i.first);

        int n = unq.size();
        vector<int> cur;
        vector<vector<int>> ans;
        auto rec = [&](int id, int rem_target, auto&& rec) -> void {
            if(rem_target < 0)
                return;

            if(!rem_target) {
                ans.push_back(cur);
                return;
            }

            if(id == n) 
                return;

            for(int i = 0; i <= cnt[unq[id]]; i++) {
                rec(id + 1, rem_target - i * unq[id], rec);
                cur.push_back(unq[id]);
            }
            for(int i = 0; i <= cnt[unq[id]]; i++)
                cur.pop_back();
        };

        rec(0, target, rec);

        return ans;
    }
};
