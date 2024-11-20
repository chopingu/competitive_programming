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
        al[b].push_back(a);
    }

    vector<ll> vis(n);
    auto dfs = [&](ll u, auto&& dfs) -> void {
        vis[u] = 1;
        for(auto v: al[u])
            if(!vis[v])
                dfs(v, dfs);
    };

    ll last = -1;
    vector<array<ll, 2>> ans;
    for(ll i = 0; i < n; i++) 
        if(!vis[i]) {
            dfs(i, dfs);
            if(last ^ -1)
                ans.push_back({last, i});
            
            last = i;
        }

    cout << sz(ans) << '\n';
    for(auto [a, b]: ans)
        cout << a + 1 << ' ' << b + 1 << '\n';
}
