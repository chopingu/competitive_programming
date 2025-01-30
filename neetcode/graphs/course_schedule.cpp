class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        return flag;
    }
};
