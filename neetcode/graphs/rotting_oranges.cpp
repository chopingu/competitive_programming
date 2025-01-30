class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int dy[] = {0, 0, 1, -1};
        const int dx[] = {1, -1, 0, 0};
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<array<int, 2>> q;
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                if(grid[i][j] == 2)
                    q.push({i, j}), dist[i][j] = 0;

        while(!q.empty()) {
            auto [y, x] = q.front();
            q.pop();

            for(int d = 0; d < 4; d++) {
                int y2 = y + dy[d], x2 = x + dx[d];
                if(y2 < 0 || y2 >= n || x2 < 0 || x2 >= m) continue;
                if(grid[y2][x2] != 1 || dist[y2][x2] != -1) continue;
                dist[y2][x2] = dist[y][x] + 1;
                q.push({y2, x2});
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                if(grid[i][j] == 1) {
                    if(dist[i][j] == -1) 
                        return -1;

                    ans = max(ans, dist[i][j]);
                }

        return ans;
    }
};
