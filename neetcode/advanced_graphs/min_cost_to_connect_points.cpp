struct dsu {
    int n, cnt;
    vector<int> r, p;

    dsu(int n) : n(n), cnt(n) {
        r.assign(n, 0);
        p.assign(n, 0);
        for(int i = 0; i < n; i++) 
            p[i] = i;
    }

    int findset(int u) { return (u == p[u]) ? u : p[u] = findset(p[u]); }

    void unionset(int u, int v) {
        int x = findset(u), y = findset(v);
        if(r[x] > r[y]) swap(x, y);
        if(r[x] == r[y]) r[y]++;
        p[x] = y;
        cnt--;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<array<int, 3>> el;
        for(int i = 0; i < points.size(); i++) 
            for(int j = i + 1; j < points.size(); j++) 
                el.push_back({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), i, j});

        int ans = 0;
        sort(el.begin(), el.end());
        dsu uf(points.size());
        for(auto e: el) {
            int w = e[0], u = e[1], v = e[2];
            if(uf.findset(u) == uf.findset(v)) continue;
            uf.unionset(u, v);
            ans += w;
            if(uf.cnt == 1) break;
        }

        return ans;
    }
};
