class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;

        int n = s.size();
        for(int i = 0; i < n; i++) {
            int le = i, ri = i;
            while(le >= 0 && ri < n && s[le] == s[ri]) {
                ans++;
                le--, ri++;
            }

            le = i, ri = i + 1;
            while(le >= 0 && ri < n && s[le] == s[ri]) {
                ans++;
                le--, ri++;
            }
        }

        return ans;
    }
};
