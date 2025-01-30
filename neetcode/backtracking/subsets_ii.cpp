class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(auto i: nums)
            cnt[i]++;

        vector<int> unq;
        for(auto i: cnt)
            unq.push_back(i.first);

        int n = unq.size();
        vector<int> cur;
        vector<vector<int>> ans;
        auto rec = [&](int id, auto&& rec) -> void {
            if(id == n) {
                ans.push_back(cur);
                return;
            }

            for(int i = 0; i <= cnt[unq[id]]; i++) {
                rec(id + 1, rec);
                cur.push_back(unq[id]);
            }
            for(int i = 0; i <= cnt[unq[id]]; i++)
                cur.pop_back();
        };

        rec(0, rec);

        return ans;
    }
};
