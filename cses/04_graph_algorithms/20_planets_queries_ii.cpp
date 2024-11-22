#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, q;
    cin >> n >> q;

    vector<vector<ll>> al(n);
    vector<vector<ll>> jmp(n, vector<ll>(31));
    for(ll i = 0; i < n; i++) { 
        cin >> jmp[i][0], --jmp[i][0];
        al[i].push_back(jmp[i][0]);
        al[jmp[i][0]].push_back(i);
    }

    for(ll i = 1; i <= 30; i++) 
        for(ll j = 0; j < n; j++)
            jmp[j][i] = jmp[jmp[j][i - 1]][i - 1];

    vector<ll> comp(n, -1);
    auto dfs1 = [&](ll u, ll id, auto&& dfs1) -> void {
        comp[u] = id;
        for(auto v: al[u])
            if(comp[v] == -1)
                dfs1(v, id, dfs1);
    };

    ll ncomps = 0;
    for(ll i = 0; i < n; i++)
        if(comp[i] == -1)
            dfs1(i, ncomps++, dfs1);

    vector<ll> cysz(ncomps), head(n), dist(n, -1);
    for(ll i = 0; i < n; i++) {
        ll u = jmp[i][30];
        for(ll cur = u;; cur = jmp[cur][0]) {
            if(dist[cur] ^ -1) break;
            dist[cur] = 0;
            head[cur] = cysz[comp[i]]++;
        }
    }

    auto dfs2 = [&](ll u, auto&& dfs2) -> void {
        ll v = jmp[u][0];
        if(dist[v] == -1)
            dfs2(v, dfs2);

        dist[u] = dist[v] + 1;
        head[u] = head[v];
    };

    for(ll i = 0; i < n; i++) 
        if(dist[i] == -1)
            dfs2(i, dfs2);

    while(q--) {
        ll a, b;
        cin >> a >> b, --a, --b;

        if(comp[a] ^ comp[b] || dist[a] < dist[b]) {
            cout << "-1\n";
            continue;
        }

        if(dist[a] && dist[b]) {
            ll cur = a, d = dist[a] - dist[b];
            for(ll i = 30; i >= 0; i--) 
                if(d & (1 << i))
                    cur = jmp[cur][i];

            if(cur ^ b)
                cout << "-1\n";
            else 
                cout << d << '\n';

            continue;
        }

        cout << dist[a] + ((head[b] - head[a]) % cysz[comp[a]] + cysz[comp[a]]) % cysz[comp[a]] << '\n';
    }
}
