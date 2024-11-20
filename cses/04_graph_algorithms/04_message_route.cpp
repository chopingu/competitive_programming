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

    vector<ll> pr(n, -1);
    pr[0] = 0;
    queue<ll> q({0});
    while(sz(q)) {
        ll u = q.front();
        q.pop();

        for(auto v: al[u]) {
            if(pr[v] ^ -1) continue;
            pr[v] = u;
            q.push(v);
        }
    }

    if(pr[n - 1] == -1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    ll cur = n - 1;
    vector<ll> ans({cur});
    while(pr[cur] ^ cur) {
        cur = pr[cur];
        ans.push_back(cur);
    }
    reverse(ans.begin(), ans.end());

    cout << sz(ans) << '\n';
    for(auto i: ans)
        cout << i + 1 << ' ';
}
