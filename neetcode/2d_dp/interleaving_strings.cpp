class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), k = s3.size();
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
        auto dp = [&](int id1, int id2, auto&& dp) -> int {
            int id3 = id1 + id2;
            if(id1 == n && id2 == m && id3 == k)
                return 1;

            if(id3 == k)
                return 0;

            int &ans = memo[id1][id2];
            if(ans ^ -1) 
                return ans;

            ans = 0;
            if(id1 < n && s1[id1] == s3[id3])
                ans |= dp(id1 + 1, id2, dp);

            if(id2 < m && s2[id2] == s3[id3])
                ans |= dp(id1, id2 + 1, dp);

            return ans;
        };

        return dp(0, 0, dp);
    }
};
