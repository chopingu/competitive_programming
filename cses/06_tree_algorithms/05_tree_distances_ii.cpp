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
        ll a, b;
        cin >> a >> b, --a, --b;

        al[a].push_back(b);
        al[b].push_back(a);
    }

    vector<ll> subtr(n), memo(n);
    auto dfs1 = [&](ll u, ll p, auto&& dfs1) -> void {
        memo[u] = 0;
        subtr[u] = 1;
        for(auto v: al[u]) 
            if(v ^ p) {
                dfs1(v, u, dfs1);
                memo[u] += memo[v] + subtr[v];
                subtr[u] += subtr[v];
            }
    };

    dfs1(0, -1, dfs1);

    auto dfs2 = [&](ll u, ll p, auto&& dfs2) -> void {
        for(auto v: al[u])
            if(v ^ p) {
                memo[v] = memo[u] - subtr[v] + (subtr[u] - subtr[v]);
                subtr[v] = subtr[u];
                dfs2(v, u, dfs2);
            }
    };

    dfs2(0, -1, dfs2);

    for(auto i: memo)
        cout << i << ' ';
}
