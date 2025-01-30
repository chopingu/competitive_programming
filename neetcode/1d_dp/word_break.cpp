class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int memo[n + 1]{};
        memo[0] = 1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < (int)wordDict.size(); j++) {
                int m = wordDict[j].size();
                if(i + m <= n && s.substr(i, m) == wordDict[j])
                    memo[i + m] |= memo[i];
            }

        return memo[n];
    }
};
