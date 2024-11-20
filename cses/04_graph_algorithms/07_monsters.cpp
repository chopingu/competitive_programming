#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    array<ll, 2> s; 
    queue<array<ll, 3>> q;
    vector<vector<ll>> dist(n, vector<ll>(m, -1));

    vector<string> grid(n);
    for(ll i = 0; i < n; i++) {
        cin >> grid[i];

        for(ll j = 0; j < m; j++) 
            if(grid[i][j] == 'A')
                s = {i, j};
            else if(grid[i][j] == 'M')
                q.push({i, j, 0}), dist[i][j] = 0;
    }

    ll dy[] = {0, 0, 1, -1};
    ll dx[] = {1, -1, 0, 0};
    string dirs = "RLDU";

    while(sz(q)) {
        auto [y, x, ign] = q.front();
        q.pop();

        for(ll d = 0; d < 4; d++) {
            ll y2 = y + dy[d], x2 = x + dx[d];
            if(y2 < 0 || y2 >= n || x2 < 0 || x2 >= m) continue;
            if(grid[y2][x2] == '#' || dist[y2][x2] ^ -1) continue;
            dist[y2][x2] = dist[y][x] + 1;
            q.push({y2, x2});
        }
    }

    vector<vector<ll>> dir(n, vector<ll>(m, -1));
    dir[s[0]][s[1]] = 4;
    q.push({s[0], s[1], 0});
    while(sz(q)) {
        auto [y, x, di] = q.front();
        q.pop();

        if(y == n - 1 || !y || x == m - 1 || !x) {
            cout << "YES\n";
            string ans;
            while(dir[y][x] ^ 4) {
                ll d = dir[y][x];
                ans.push_back(dirs[d]);
                y -= dy[d], x -= dx[d];
            }
            reverse(ans.begin(), ans.end());

            cout << sz(ans) << '\n' << ans;
            return 0;
        }

        for(ll d = 0; d < 4; d++) {
            ll y2 = y + dy[d], x2 = x + dx[d];
            if(y2 < 0 || y2 >= n || x2 < 0 || x2 >= m) continue;
            if(grid[y2][x2] == '#' || dir[y2][x2] ^ -1) continue;
            if(dist[y2][x2] ^ -1 && dist[y2][x2] <= di + 1) continue;
            dir[y2][x2] = d;
            q.push({y2, x2, di + 1});
        }
    }

    cout << "NO";
}
