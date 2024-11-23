#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    vector<ll> out(n), in(n);
    vector<vector<ll>> al(n), al_u(n);
    for(ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        al[a].push_back(b);
        al_u[a].push_back(b);
        al_u[b].push_back(a);
        out[a]++, in[b]++;
    }

    if(out[0] != in[0] + 1 || in[n - 1] != out[n - 1] + 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for(ll i = 1; i < n - 1; i++) 
        if(out[i] ^ in[i]) {
            cout << "IMPOSSIBLE";
            return 0;
        }

    vector<ll> vis(n);
    auto dfs = [&](ll u, auto&& dfs) -> void {
        vis[u] = 1;
        for(auto v: al_u[u])
            if(!vis[v])
                dfs(v, dfs);
    };

    dfs(0, dfs);

    for(ll i = 0; i < n; i++)
        if(!vis[i] && (i == n - 1 || (in[i] + out[i]))) {
            cout << "IMPOSSIBLE";
            return 0;
        }

    vector<ll> ans;
    stack<ll> st({0});
    while(sz(st)) {
        ll u = st.top();
        if(--out[u] < 0) {
            ans.push_back(u);
            st.pop();
            continue;
        }
        st.push(al[u][out[u]]);
    }
    reverse(ans.begin(), ans.end()); 

    for(auto i: ans)
        cout << i + 1 << ' ';
}
