class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> al(numCourses, vector<int>());
        for(auto a: prerequisites) 
            al[a[1]].push_back(a[0]);

        bool flag = true;
        vector<int> vis(numCourses);
        auto dfs = [&](int u, auto&& dfs) -> void {
            vis[u] = 1;
            for(auto v: al[u]) 
                if(vis[v] == 1) 
                    flag = false;
                else
                    dfs(v, dfs);

            vis[u] = 2;
        };

        for(int i = 0; i < numCourses; i++) 
            if(!vis[i])
                dfs(i, dfs);

        if(!flag) 
            return {};

        vector<int> ans;
        vis.assign(numCourses, 0);
        auto dfs2 = [&](int u, auto&& dfs2) -> void {
            vis[u] = 1;
            for(auto v: al[u])
                if(!vis[v])
                    dfs2(v, dfs2);

            ans.push_back(u);
        };

        for(int i = 0; i < numCourses; i++)
            if(!vis[i])
                dfs2(i, dfs2);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
