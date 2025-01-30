class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> points;
        for(auto inter: intervals) {
            points.push_back(inter[0]);
            points.push_back(inter[1]);
        }
        for(auto i: queries)
            points.push_back(i);

        sort(points.begin(), points.end());

        int n = 0;
        unordered_map<int, int> comp;
        for(auto i: points)
            if(comp.find(i) == comp.end())
                comp[i] = n++;

        vector<int> seg(4*n, 1e9), lzmin(4*n, 1e9);
        auto push = [&](int v) -> void {
            if(lzmin[v] == 1e9)
                return;

            seg[2*v] = min(seg[2*v], lzmin[v]);
            seg[2*v + 1] = min(seg[2*v + 1], lzmin[v]);
            lzmin[2*v] = min(lzmin[2*v], lzmin[v]);
            lzmin[2*v + 1] = min(lzmin[2*v + 1], lzmin[v]);
            lzmin[v] = 1e9;
        };

        auto upd = [&](int v, int tl, int tr, int le, int ri, int val, auto&& upd) -> void {
            if(le > ri) return;
            if(le == tl && ri == tr) {
                seg[v] = min(seg[v], val);
                lzmin[v] = min(lzmin[v], val);
                return;
            }
            push(v);
            int tm = tl + (tr - tl) / 2;
            upd(2*v, tl, tm, le, min(tm, ri), val, upd);
            upd(2*v + 1, tm + 1, tr, max(tm + 1, le), ri, val, upd);
        };

        auto qry = [&](int v, int tl, int tr, int pos, auto&& qry) -> int {
            if(tl == tr)
                return seg[v];

            push(v);
            int tm = tl + (tr - tl) / 2;
            return (pos <= tm) ? qry(2*v, tl, tm, pos, qry) : qry(2*v + 1, tm + 1, tr, pos, qry);
        };

        for(auto inter: intervals)
            upd(1, 0, n - 1, comp[inter[0]], comp[inter[1]], inter[1] - inter[0] + 1, upd);

        vector<int> ans(queries.size());
        for(int i = 0; i < ans.size(); i++) {
            int val = qry(1, 0, n - 1, comp[queries[i]], qry);
            ans[i] = (val == 1e9) ? -1 : val;
        }

        return ans;
    }
};
