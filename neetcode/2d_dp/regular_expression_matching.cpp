class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
        auto dp = [&](int id1, int id2, auto&& dp) -> int {
            if(id1 == n && id2 == m) 
                return 1;

            if(id2 == m)
                return 0;

            int &ans = memo[id1][id2];
            if(ans ^ -1)
                return ans;

            ans = 0;                
            if(id2 + 1 < m && p[id2 + 1] == '*') {
                int cnt = 0;
                while(id1 + cnt <= n) {
                    ans |= dp(id1 + cnt, id2 + 2, dp);
                    if(id1 + cnt == n || (p[id2] != '.' && s[id1 + cnt] != p[id2])) break;
                    cnt++;
                }
                return ans;
            } 

            if(id1 < n && p[id2] == '.') {
                ans |= dp(id1 + 1, id2 + 1, dp);
                return ans;
            }

            if(id1 < n && p[id2] == s[id1]) 
                ans |= dp(id1 + 1, id2 + 1, dp);

            return ans;
        };

        return dp(0, 0, dp);
    }
};
