#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    multiset<ll> h;
    for(ll i = 0; i < n; i++) {
        ll a;
        cin >> a;

        h.insert(a);
    }

    vector<ll> ans(m, -1);
    for(ll i = 0; i < m; i++) {
        ll a;
        cin >> a;

        auto it = h.upper_bound(a);
        if(it == h.begin()) 
            continue;

        --it;
        ans[i] = *it;
        h.erase(it);
    }

    for(auto i: ans)
        cout << i << '\n';
}
