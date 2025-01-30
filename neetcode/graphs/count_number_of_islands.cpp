class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int dy[] = {0, 0, 1, -1};
        const int dx[] = {1, -1, 0, 0};
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        auto dfs = [&](int y, int x, auto&& dfs) -> void {
            vis[y][x] = true;
            for(int d = 0; d < 4; d++) {
                int y2 = y + dy[d], x2 = x + dx[d];
                if(y2 < 0 || y2 >= n || x2 < 0 || x2 >= m) continue;
                if(grid[y2][x2] == '0' || vis[y2][x2]) continue;
                dfs(y2, x2, dfs);
            }
        };

        int ans = 0;
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                if(!vis[i][j] && grid[i][j] == '1')
                    dfs(i, j, dfs), ans++;

        return ans;
    }
};
