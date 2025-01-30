class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int dy[] = {0, 0, 1, -1};
        const int dx[] = {1, -1, 0, 0};

        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        auto dfs = [&](int y, int x, int id, auto&& dfs) -> bool {
            if(id == (int)word.size() - 1) {
                if(board[y][x] == word[id])
                    return true;
                
                return false;
            }
            
            if(board[y][x] != word[id]) 
                return false;

            vis[y][x] = 1;
            for(int d = 0; d < 4; d++) {
                int y2 = y + dy[d], x2 = x + dx[d];
                if(y2 < 0 || y2 >= n || x2 < 0 || x2 >= m || vis[y2][x2]) continue;
                if(dfs(y2, x2, id + 1, dfs))
                    return true;
            }
            vis[y][x] = 0;
            
            return false;
        };

        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) {
                vis.assign(n, vector<int>(m, 0));
                if(dfs(i, j, 0, dfs))
                    return true;
            }

        return false;
    }
};
