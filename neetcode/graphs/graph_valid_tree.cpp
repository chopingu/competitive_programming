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
        if(x == y) return;
        if(r[x] > r[y]) 
            swap(x, y);

        if(r[x] == r[y]) 
            r[y]++;

        p[x] = y;
        cnt--;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        dsu uf(n);
        for(auto e: edges) {
            if(uf.findset(e[0]) == uf.findset(e[1]))
                return false;

            uf.unionset(e[0], e[1]);
        }

        return uf.cnt == 1;
    }
};
