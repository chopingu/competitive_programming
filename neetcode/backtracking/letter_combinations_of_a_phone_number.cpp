class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return vector<string>();

        vector<string> pad = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string cur = "";
        vector<string> ans;
        auto rec = [&](int id, auto&& rec) -> void {
            if(id == digits.size()) {
                ans.push_back(cur);
                return;
            }

            for(auto ch: pad[digits[id] - '2']) {
                cur.push_back(ch);
                rec(id + 1, rec);
                cur.pop_back();
            }
        };

        rec(0, rec);

        return ans;
    }
};
