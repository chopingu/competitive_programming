class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> cur;
        vector<vector<string>> ans;
        auto rec = [&](int last, int id, auto&& rec) -> void {
            if(id == n && last == n) {
                ans.push_back(cur);
                return;
            }
            if(id == n)
                return;

            bool flag = true;
            int len = id - last + 1;
            for(int i = 0; i < len / 2; i++) 
                flag &= (s[last + i] == s[id - i]);

            if(flag) {
                string tmp = "";
                for(int i = last; i <= id; i++) 
                    tmp.push_back(s[i]);

                cur.push_back(tmp);
                rec(id + 1, id + 1, rec);
                cur.pop_back();
            }

            rec(last, id + 1, rec);
        };

        rec(0, 0, rec);

        return ans;
    }
};
