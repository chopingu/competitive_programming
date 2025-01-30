class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") 
            return "0";

        vector<int> ans(num1.length() + num2.length(), 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i = 0; i < num1.length(); i++) 
            for(int j = 0; j < num2.length(); j++) {
                int dig = (num1[i] - '0') * (num2[j] - '0');
                ans[i + j] += dig;
                ans[i + j + 1] += ans[i + j] / 10;
                ans[i + j] %= 10;
            }

        string prod = "";
        int id = ans.size() - 1;
        while(id >= 0 && ans[id] == 0) 
            id--;

        while(id >= 0) 
            prod.push_back(ans[id--] + '0');

        return prod;
    }
};
