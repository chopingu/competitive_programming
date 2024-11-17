#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<array<ll, 2>> m;
    for(ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        m.push_back({b, a});
    }
    sort(m.begin(), m.end());

    ll ans = 0, last = 0;
    for(auto [b, a]: m)
        if(a >= last) 
            ans++, last = b;

    cout << ans;
}
