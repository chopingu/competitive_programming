class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.size();
        unordered_map<string, vector<string>> al;

        vector<string> allw(wordList.begin(), wordList.end());
        allw.push_back(beginWord);
        for(auto s: allw)
            for(int i = 0; i < n; i++) {
                string tmp = s.substr(0, i) + '*' + s.substr(i + 1);
                al[tmp].push_back(s);
                al[s].push_back(tmp);
            }

        unordered_map<string, int> dist;
        auto dfs = [&](string u, auto&& dfs) -> void {
            if(u == endWord) {
                dist[u] = 0;
                return;
            }

            dist[u] = 1e9;
            for(auto v: al[u]) {
                if(dist.find(v) == dist.end())
                    dfs(v, dfs);

                dist[u] = min(dist[u], dist[v] + 1);
            }
        };

        dfs(beginWord, dfs);

        if(dist[beginWord] == 1e9)
            return 0;

        return (dist[beginWord] + 2) / 2;
    }
};
