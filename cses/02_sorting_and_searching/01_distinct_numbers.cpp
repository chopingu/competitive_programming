#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    set<ll> s;
    for(ll i = 0; i < n; i++) {
        ll a;
        cin >> a;
        
        s.insert(a);
    }

    cout << sz(s);
}
