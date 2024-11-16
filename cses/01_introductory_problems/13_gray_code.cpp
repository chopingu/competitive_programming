#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<vector<ll>> al(1 << n, vector<ll>());
    for(ll i = 0; i < (1 << n); i++)
        for(ll j = 0; j < n; j++)
            al[i].push_back(i ^ (1 << j));

    vector<ll> vis(1 << n);
    auto dfs = [&](ll u, auto&& dfs) -> void {
        for(ll i = 0; i < n; i++)
            cout << !!(u & (1 << i));

        cout << '\n';

        vis[u] = 1;
        for(auto v: al[u])
            if(!vis[v]) 
                dfs(v, dfs);
    };

    dfs(0, dfs);
}
