class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int mx = 0;

        int n = s.size();
        for(int i = 0; i < n; i++) {
            int le = i, ri = i;
            while(le >= 0 && ri < n && s[le] == s[ri]) {
                if(ri - le + 1 > mx) {
                    ans = s.substr(le, ri - le + 1);
                    mx = ri - le + 1;
                }
                le--, ri++;
            }

            le = i, ri = i + 1;
            while(le >= 0 && ri < n && s[le] == s[ri]) {
                if(ri - le + 1 > mx) {
                    ans = s.substr(le, ri - le + 1);
                    mx = ri - le + 1;
                }
                le--, ri++;
            }
        }

        return ans;
    }
};
