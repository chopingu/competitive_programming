class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int dy[] = {0, 0, 1, -1};
        const int dx[] = {1, -1, 0, 0};

        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n));
        auto dfs = [&](int y, int x, int mid, auto&& dfs) -> void {
            if(grid[y][x] > mid) 
                return;
                
            vis[y][x] = 1;
            for(int d = 0; d < 4; d++) {
                int y2 = y + dy[d], x2 = x + dx[d];
                if(y2 < 0 || y2 >= n || x2 < 0 || x2 >= n) continue;
                if(grid[y2][x2] > mid || vis[y2][x2]) continue;
                dfs(y2, x2, mid, dfs);
            }
        };

        int lo = 0, hi = 1e9, ans = 0;
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            vis.assign(n, vector<int>(n));
            dfs(0, 0, mid, dfs);
            (vis[n - 1][n - 1]) ? ans = mid, hi = mid - 1 : lo = mid + 1;
        }

        return ans;
    }
};
