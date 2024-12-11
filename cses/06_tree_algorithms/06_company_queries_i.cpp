#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, q;
    cin >> n >> q;

    vector<vector<ll>> al(n);
    for(ll i = 0; i < n - 1; i++) {
        ll a;
        cin >> a, --a;

        al[a].push_back(i + 1);
    }

    vector<vector<ll>> jmp(n, vector<ll>(31, -1));
    auto dfs = [&](ll u, ll p, auto&& dfs) -> void {
        jmp[u][0] = p;
        for(ll i = 1; i <= 30; i++) {
            if(jmp[u][i - 1] == -1) 
                break;

            jmp[u][i] = jmp[jmp[u][i - 1]][i - 1];
        }

        for(auto v: al[u])
            if(v ^ p)
                dfs(v, u, dfs);
    };

    dfs(0, -1, dfs);

    while(q--) {
        ll x, k;
        cin >> x >> k, --x;

        for(ll i = 30; i >= 0; i--) 
            if(k & (1 << i)) {
                x = jmp[x][i];
                if(x == -1) 
                    break;
            }

        if(x == -1) 
            cout << x << '\n';
        else 
            cout << x + 1 << '\n';
    }
}
