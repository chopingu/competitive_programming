#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for(auto &i: a)
        cin >> i;

    map<ll, array<ll, 2>> mp; 
    for(ll i = 0; i < n; i++) {
        for(ll j = i + 1; j < n; j++) 
            if(mp.find(x - a[i] - a[j]) != mp.end()) {
                auto [c1, c2] = mp[x - a[i] - a[j]];
                cout << c1 + 1 << ' ' << c2 + 1 << ' ' << i + 1 << ' ' << j + 1 << '\n';
                return 0;
            }

        for(ll j = 0; j < i; j++) 
            mp[a[i] + a[j]] = {j, i};
    }

    cout << "IMPOSSIBLE";
}
