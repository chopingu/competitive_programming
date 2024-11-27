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

    vector<array<ll, 3>> mx(n);
    auto dfs1 = [&](ll u, ll p, auto&& dfs1) -> void {
        ll mx1 = 0, mx2 = 0, id = -1;
        for(auto v: al[u])
            if(v ^ p) {
                dfs1(v, u, dfs1);
                if(mx[v][0] + 1 >= mx1) {
                    id = v;
                    mx2 = mx1;
                    mx1 = mx[v][0] + 1;
                }
                else if(mx[v][0] + 1 > mx2)
                    mx2 = mx[v][0] + 1;
            }

        mx[u] = {mx1, mx2, id};
    };

    dfs1(0, -1, dfs1);

    auto dfs2 = [&](ll u, ll p, auto&& dfs2) -> void {
        for(auto v: al[u]) 
            if(v ^ p) {
                if(v == mx[u][2]) {
                    if(mx[u][1] + 1 >= mx[v][0]) {
                        mx[v][2] = u;
                        mx[v][1] = mx[v][0];
                        mx[v][0] = mx[u][1] + 1;
                    }
                    else if(mx[u][1] + 1 > mx[v][1])
                        mx[v][1] = mx[u][1] + 1;

                }
                else {
                    if(mx[u][0] + 1 >= mx[v][0]) {
                        mx[v][2] = u;
                        mx[v][1] = mx[v][0];
                        mx[v][0] = mx[u][0] + 1;
                    }
                    else if(mx[u][0] + 1 > mx[v][1])
                        mx[v][1] = mx[u][0] + 1;
                }
                dfs2(v, u, dfs2);
            }
    };

    dfs2(0, -1, dfs2);

    for(ll i = 0; i < n; i++) 
        cout << mx[i][0] << ' ';
}
