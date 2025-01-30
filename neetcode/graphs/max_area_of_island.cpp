class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int dy[] = {0, 0, 1, -1};
        const int dx[] = {1, -1, 0, 0};

        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        auto dfs = [&](int y, int x, auto&& dfs) -> int {
            vis[y][x] = true;

            int cnt = 1;
            for(int d = 0; d < 4; d++) {
                int y2 = y + dy[d], x2 = x + dx[d];
                if(y2 < 0 || y2 >= n || x2 < 0 || x2 >= m) continue;
                if(!grid[y2][x2] || vis[y2][x2]) continue;
                cnt += dfs(y2, x2, dfs);
            }

            return cnt;
        };

        int ans = 0;
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                if(grid[i][j] && !vis[i][j])
                    ans = max(ans, dfs(i, j, dfs));

        return ans;
    }
};
