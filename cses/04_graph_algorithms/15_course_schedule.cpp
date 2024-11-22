#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> al(n);
    for(ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        al[a].push_back(b);
    }

    vector<ll> vis(n), ans;
    auto dfs = [&](ll u, auto&& dfs) -> void {
        vis[u] = 1;
        for(auto v: al[u])
            if(vis[v] == 1) {
                cout << "IMPOSSIBLE";
                exit(0);
            }
            else if(!vis[v])
                dfs(v, dfs);

        ans.push_back(u);
        vis[u] = 2;
    };

    for(ll i = 0; i < n; i++) 
        if(!vis[i]) 
            dfs(i, dfs);

    reverse(ans.begin(), ans.end());
    for(auto i: ans)
        cout << i + 1 << ' ';
}
