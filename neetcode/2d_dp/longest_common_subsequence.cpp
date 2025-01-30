class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        int memo[n + 1][m + 1]{};
        for(int i = 0; i <= n; i++) 
            for(int j = 0; j <= m; j++) {
                if(i + 1 <= n)
                    memo[i + 1][j] = max(memo[i + 1][j], memo[i][j]);

                if(j + 1 <= m)
                    memo[i][j + 1] = max(memo[i][j + 1], memo[i][j]);

                if(i + 1 <= n && j + 1 <= m)
                    memo[i + 1][j + 1] = max(memo[i + 1][j + 1], memo[i][j] + (text1[i] == text2[j]));
            }

        return memo[n][m];
    }
};
