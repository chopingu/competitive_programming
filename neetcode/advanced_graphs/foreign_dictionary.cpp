class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> al(26, vector<int>());
        for(int i = 0; i < words.size() - 1; i++) {
            int flag = 0;
            string a = words[i], b = words[i + 1];
            for(int j = 0; j < min(a.size(), b.size()); j++)
                if(a[j] != b[j]) {
                    al[a[j] - 'a'].push_back(b[j] - 'a');
                    flag = 1;
                    break;
                }
            
            if(!flag && a.size() > b.size())
                return "";
        }

        int flag = 0;
        vector<int> vis(26);
        auto dfs1 = [&](int u, auto&& dfs1) -> void {
            vis[u] = 1;
            for(auto v: al[u])
                if(vis[v] == 1) 
                    flag = 1;
                else if(!vis[v])
                    dfs1(v, dfs1);

            vis[u] = 2;
        };

        for(int i = 0; i < 26; i++)
            if(!vis[i])
                dfs1(i, dfs1);

        if(flag)
            return "";

        string ans = "";
        auto dfs2 = [&](int u, auto&& dfs2) -> void {
            vis[u] = 1;
            for(auto v: al[u])
                if(!vis[v])
                    dfs2(v, dfs2);

            ans.push_back((char)(u + 'a'));
        };

        vis.assign(26, 0);
        for(int i = 0; i < 26; i++) 
            if(!vis[i]) 
                dfs2(i, dfs2);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
