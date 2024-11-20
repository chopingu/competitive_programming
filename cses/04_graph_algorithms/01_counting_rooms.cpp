#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(auto &i: grid)
        cin >> i;

    vector<ll> dy = {0, 0, 1, -1};
    vector<ll> dx = {1, -1, 0, 0};
    vector<vector<ll>> vis(n, vector<ll>(m));
    auto dfs = [&](ll y, ll x, auto&& dfs) -> void {
        vis[y][x] = 1;
        for(ll d = 0; d < 4; d++) {
            ll y2 = y + dy[d], x2 = x + dx[d];
            if(y2 < 0 || y2 >= n || x2 < 0 || x2 >= m) continue;
            if(vis[y2][x2] || grid[y2][x2] == '#') continue;
            dfs(y2, x2, dfs);
        }
    };

    ll ans = 0;
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++)
            if(!vis[i][j] && grid[i][j] == '.')
                dfs(i, j, dfs), ans++;

    cout << ans;
}
