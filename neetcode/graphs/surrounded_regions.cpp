class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int dy[] = {0, 0, 1, -1};
        const int dx[] = {1, -1, 0, 0};
        int n = board.size(), m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m)), bor(n, vector<int>(m));
        auto dfs = [&](int y, int x, auto&& dfs) -> void {
            for(int d = 0; d < 4; d++) {
                int y2 = y + dy[d], x2 = x + dx[d];
                if(y2 < 0 || y2 >= n || x2 < 0 || x2 >= m) continue;
                if(board[y2][x2] == 'X' || vis[y2][x2]) continue;
                vis[y2][x2] = 1;
                dfs(y2, x2, dfs);
            }
        };

        for(int i = 0; i < n; i++) {
            dfs(i, -1, dfs);
            dfs(i, m, dfs);
        }
        for(int i = 0; i < m; i++) {
            dfs(-1, i, dfs);
            dfs(n, i, dfs);
        }

        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++)
                if(board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
    }
};
