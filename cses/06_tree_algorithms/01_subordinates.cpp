#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<vector<ll>> al(n);
    for(ll i = 0; i < n - 1; i++) {
        ll a;
        cin >> a, --a;

        al[a].push_back(i + 1);
    }

    vector<ll> subtr(n);
    auto dfs = [&](ll u, auto&& dfs) -> void {
        subtr[u] = 1;
        for(auto v: al[u]) {
            if(!subtr[v])
                dfs(v, dfs);

            subtr[u] += subtr[v];
        }
    };

    for(ll i = 0; i < n; i++)
        if(!subtr[i])
            dfs(i, dfs);

    for(ll i = 0; i < n; i++) 
        cout << subtr[i] - 1 << ' ';
}
