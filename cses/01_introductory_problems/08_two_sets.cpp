#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    ll v = n * (n + 1) / 2;
    if(v & 1) {
        cout << "NO";
        return 0;
    }
    v /= 2;

    vector<ll> a, b;
    for(ll i = n; i >= 1; i--) 
        if(v >= i) 
            v -= i, a.push_back(i);
        else 
            b.push_back(i);

    cout << "YES\n" << sz(a) << '\n';
    for(auto i: a)
        cout << i << ' ';

    cout << '\n' << sz(b) << '\n';
    for(auto i: b) 
        cout << i << ' ';
}
