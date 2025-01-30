class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int memo[n + 1]{};
        memo[0] = 1;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0')
                continue;

            memo[i + 1] += memo[i];
            if(i < n - 1 && stoi(s.substr(i, 2)) <= 26)
                memo[i + 2] += memo[i];
        }

        return memo[n];
    }
};
