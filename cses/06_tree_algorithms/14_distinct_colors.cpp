#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<set<ll>> tmp(n);
    for(ll i = 0; i < n; i++) {
        ll a; 
        cin >> a;

        tmp[i].insert(a);
    }

    vector<vector<ll>> al(n);
    for(ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        al[a].push_back(b);
        al[b].push_back(a);
    }

    vector<ll> ans(n);
    auto dfs = [&](ll u, ll p, auto&& dfs) -> void {
        for(auto v: al[u])
            if(v ^ p) {
                dfs(v, u, dfs);
                if(sz(tmp[u]) < sz(tmp[v]))
                    swap(tmp[u], tmp[v]);

                for(auto i: tmp[v])
                    tmp[u].insert(i);
            }

        ans[u] = sz(tmp[u]);
    };

    dfs(0, -1, dfs);

    for(ll i = 0; i < n; i++)
        cout << ans[i] << ' ';
}
