class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0, carry = 0;
        for(int i = 0; i < 32; i++) {
            int tmp1 = (1 << i) & a;
            int tmp2 = (1 << i) & b;
            int bit = tmp1 ^ tmp2 ^ carry;
            if((tmp1 & tmp2) || (tmp1 & carry) || (tmp2 & carry))
                carry = (1 << i) << 1;

            ans |= bit;
        }

        return ans;
    }
};
