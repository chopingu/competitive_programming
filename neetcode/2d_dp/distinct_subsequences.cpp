class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        int memo[n + 1][m + 1]{};
        memo[0][0] = 1;
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++) {
                if(i == n && j == m) continue;
                if(i < n && j < m && s[i] == t[j])
                    memo[i + 1][j + 1] += memo[i][j];
                if(i < n)
                    memo[i + 1][j] += memo[i][j];
            }

        return memo[n][m];
    }
};
