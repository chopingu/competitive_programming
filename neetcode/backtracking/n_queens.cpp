class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> row(n), di1(2*n - 1), di2(2*n - 1); 
        vector<string> cur(n, string(n, '.'));
        vector<vector<string>> ans;
        auto rec = [&](int id, auto&& rec) -> void {
            if(id == n) {
                ans.push_back(cur);
                return;
            }

            for(int i = 0; i < n; i++) {
                if(row[i]) continue;
                if(di1[i - id + n - 1]) continue;
                if(di2[i + id]) continue;
                row[i] = di1[i - id + n - 1] = di2[i + id] = true;
                cur[i][id] = 'Q';
                rec(id + 1, rec);
                row[i] = di1[i - id + n - 1] = di2[i + id] = false;
                cur[i][id] = '.';
            }
        };

        rec(0, rec);

        return ans;
    }
};
