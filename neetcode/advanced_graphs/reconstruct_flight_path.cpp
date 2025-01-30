class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_set<string> nodes;
        unordered_map<string, int> deg;
        unordered_map<string, vector<string>> al;
        for(auto e: tickets) {
            nodes.insert(e[0]);
            nodes.insert(e[1]);
            al[e[0]].push_back(e[1]);
            deg[e[0]]++;
        }
        
        for(auto &it: al) {
            sort(it.second.begin(), it.second.end());
            reverse(it.second.begin(), it.second.end());
        }

        vector<string> ans;
        stack<string> st;
        st.push("JFK");
        while(!st.empty()) {
            string u = st.top();
            if(--deg[u] < 0) {
                ans.push_back(u);
                st.pop();
                continue;
            }
            st.push(al[u][deg[u]]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
