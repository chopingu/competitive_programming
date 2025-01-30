class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int memo[n + 1][m + 1];
        memset(memo, 0x3f, sizeof memo);
        memo[0][0] = 0;
        for(int i = 0; i <= n; i++) 
            for(int j = 0; j <= m; j++) {
                if(i < n && j < m)
                    memo[i + 1][j + 1] = min(memo[i + 1][j + 1], memo[i][j] + (word1[i] != word2[j]));

                if(j < m)
                    memo[i][j + 1] = min(memo[i][j + 1], memo[i][j] + 1);

                if(i < n)
                    memo[i + 1][j] = min(memo[i + 1][j], memo[i][j] + 1);
            }

        return memo[n][m];
    }
};
