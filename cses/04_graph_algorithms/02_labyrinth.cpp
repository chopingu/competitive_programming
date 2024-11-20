#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    array<ll, 2> s, g;
    vector<string> grid;
    for(ll i = 0; i < n; i++) {
        string a;
        cin >> a;

        grid.push_back(a);
        for(ll j = 0; j < m; j++) 
            if(a[j] == 'A')
                s = {i, j};
            else if(a[j] == 'B')
                g = {i, j};
    }

    const ll dy[] = {0, 0, 1, -1};
    const ll dx[] = {1, -1, 0, 0};
    string dirs = "RLDU";
    
    ll dist[n][m], dir[n][m];
    memset(dir, -1, sizeof dir);
    memset(dist, -1, sizeof dist);
    dist[s[0]][s[1]] = 0;

    queue<array<ll, 2>> q({s});
    while(sz(q)) {
        auto [y, x] = q.front();
        q.pop();

        for(ll d = 0; d < 4; d++) {
            ll y2 = y + dy[d], x2 = x + dx[d];
            if(y2 < 0 || y2 >= n || x2 < 0 || x2 >= m) continue;
            if(grid[y2][x2] == '#' || dist[y2][x2] ^ -1) continue;
            dist[y2][x2] = dist[y][x] + 1;
            dir[y2][x2] = d;
            q.push({y2, x2});
        }
    }

    if(dist[g[0]][g[1]] == -1) {
        cout << "NO";
        return 0;
    }

    ll y = g[0], x = g[1];
    string ans;
    while(dir[y][x] ^ -1) {
        ll d = dir[y][x];
        ans.push_back(dirs[d]);
        y -= dy[d], x -= dx[d];
    }
    reverse(ans.begin(), ans.end());

    cout << "YES\n" << sz(ans) << '\n' << ans;
}
