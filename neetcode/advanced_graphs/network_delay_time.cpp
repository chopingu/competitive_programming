class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         vector<vector<array<int, 2>>> al(n, vector<array<int, 2>>());
         for(auto e: times)
             al[e[0] - 1].push_back({e[1] - 1, e[2]});

         vector<int> dist(n, 1e9);
         dist[k - 1] = 0;
         set<array<int, 2>> pq;
         for(int i = 0; i < n; i++)
            pq.insert({dist[i], i});
            
         while(!pq.empty()) {
             auto tmp = *pq.begin();
             int d = tmp[0], u = tmp[1];
             pq.erase(pq.begin());
             
             for(auto e: al[u]) {
                 int v = e[0], w = e[1];
                 if(dist[u] + w >= dist[v]) continue;
                 pq.erase(pq.find({dist[v], v}));
                 dist[v] = dist[u] + w;
                 pq.insert({dist[v], v});
             }
         }

         int ans = 0;
         for(int i = 0; i < n; i++) 
             ans = max(ans, dist[i]);

         if(ans == 1e9)
             return -1;

         return ans;
    }
};
