class Solution {
public:
    bool checkValidString(string s) {
        int cnt1 = 0, cnt2 = 0;
        for(auto ch: s) {
            if(ch == '(') {
                cnt1++;
                cnt2++;
            }
            if(ch == ')') {
                cnt1--;
                cnt2--;
            }
            if(ch == '*') {
                cnt1--;
                cnt2++;
            }

            if(cnt2 < 0) 
                return false;

            if(cnt1 < 0)
                cnt1 = 0;
        }

        return (cnt1 == 0);
    }
};
