#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    multiset<ll> ms;
    for(ll i = 0; i < n; i++) {
        ll a;
        cin >> a;

        auto it = ms.upper_bound(a);
        if(it == ms.end()) {
            ms.insert(a);
            continue;
        }

        ms.erase(it);
        ms.insert(a);
    }

    cout << sz(ms);
}
