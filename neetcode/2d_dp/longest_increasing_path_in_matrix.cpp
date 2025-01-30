class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int dy[] = {0, 0, 1, -1};
        const int dx[] = {1, -1, 0, 0};

        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        auto dp = [&](int y, int x, auto&& dp) -> int {
            int &ans = memo[y][x];
            if(ans ^ -1)
                return ans;

            ans = 1;
            for(int d = 0; d < 4; d++) {
                int y2 = y + dy[d], x2 = x + dx[d];
                if(y2 < 0 || y2 >= n || x2 < 0 || x2 >= m) continue;
                if(matrix[y2][x2] <= matrix[y][x]) continue;
                ans = max(ans, dp(y2, x2, dp) + 1);
            }

            return ans;
        };

        int ans = 0;
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                ans = max(ans, dp(i, j, dp));

        return ans;
    }
};
