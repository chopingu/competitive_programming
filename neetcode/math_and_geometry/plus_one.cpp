class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> ans;
        for(int i = digits.size() - 1; i >= 0; i--) {
            int val = digits[i] + carry;
            carry = val / 10;
            val %= 10;
            ans.push_back(val);
        }
        if(carry) 
            ans.push_back(carry);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
