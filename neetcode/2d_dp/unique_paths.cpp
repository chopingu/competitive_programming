class Solution {
public:
    int uniquePaths(int m, int n) {
        const int dy[] = {0, 1};
        const int dx[] = {1, 0};

        int memo[m][n]{};
        memo[0][0] = 1;
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++)
                for(int d = 0; d < 2; d++) {
                    int y2 = i + dy[d], x2 = j + dx[d];
                    if(y2 >= m || x2 >= n) continue;
                    memo[y2][x2] += memo[i][j];
                }

        return memo[m - 1][n - 1];
    }
};
