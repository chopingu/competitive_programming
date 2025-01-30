class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int dy[] = {0, 0, 1, -1};
        const int dx[] = {1, -1, 0, 0};
        
        int n = grid.size(), m = grid[0].size();
        queue<array<int, 2>> q;
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                if(!grid[i][j])
                    q.push({i, j});

        const int INF = 2147483647;
        while(!q.empty()) {
            auto tmp = q.front();
            q.pop();
            int y = tmp[0], x = tmp[1];

            for(int d = 0; d < 4; d++) {
                int y2 = y + dy[d], x2 = x + dx[d];
                if(y2 < 0 || y2 >= n || x2 < 0 || x2 >= m) continue;
                if(grid[y2][x2] != INF) continue;
                grid[y2][x2] = grid[y][x] + 1;
                q.push({y2, x2});
            }
        }
    }
};
