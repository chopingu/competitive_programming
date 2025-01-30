class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        const int dy[] = {0, 0, 1, -1};
        const int dx[] = {1, -1, 0, 0};
        int n = heights.size(), m = heights[0].size();

        vector<vector<int>> vis(n, vector<int>(m));
        vector<vector<int>> pac(n, vector<int>(m)), atl(n, vector<int>(m));
        auto dfs = [&](int y, int x, auto&& dfs) -> void {
            vis[y][x] = 1;
            for(int d = 0; d < 4; d++) {
                int y2 = y + dy[d], x2 = x + dx[d];
                if(y2 < 0 || x2 < 0) 
                    pac[y][x] = 1;

                if(y2 >= n || x2 >= m) 
                    atl[y][x] = 1;

                if(y2 < 0 || x2 < 0 || y2 >= n || x2 >= m)
                    continue;

                if(heights[y2][x2] > heights[y][x]) 
                    continue;

                if(!vis[y2][x2])
                    dfs(y2, x2, dfs);

                pac[y][x] |= pac[y2][x2];
                atl[y][x] |= atl[y2][x2];
            }
        };

        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                dfs(i, j, dfs);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) 
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i, j}); 

        return ans;
    }
};
