class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<array<int, 2>>> al(n, vector<array<int, 2>>());
        for(auto e: flights) 
            al[e[0]].push_back({e[1], e[2]});

        vector<vector<int>> dist(n, vector<int>(k + 2, 1e9));
        dist[src][0] = 0;
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        pq.push({dist[src][0], 0, src});
        while(!pq.empty()) {
            auto tmp = pq.top();
            pq.pop();

            int d = tmp[0], cnt = tmp[1], u = tmp[2];
            if(d > dist[u][cnt]) continue;

            for(auto e: al[u]) {
                int v = e[0], w = e[1];
                if(cnt + 1 > k + 1) continue;
                if(dist[u][cnt] + w >= dist[v][cnt + 1]) continue;
                dist[v][cnt + 1] = dist[u][cnt] + w;
                pq.push({dist[v][cnt + 1], cnt + 1, v});
            }
        }

        int ans = 1e9;
        for(int i = 0; i <= k + 1; i++)
            ans = min(ans, dist[dst][i]);

        if(ans >= 1e9) 
            return -1;

        return ans;
    }
};
