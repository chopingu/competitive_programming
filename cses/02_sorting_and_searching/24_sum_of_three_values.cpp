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
 
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++) {
        for(ll j = i + 1; j < n; j++) {
            if(mp.find(x - a[i] - a[j]) != mp.end()) {
                cout << mp[x - a[i] - a[j]] + 1 << ' ' << i + 1 << ' ' << j + 1;
                return 0;
            }
        }
        mp[a[i]] = i;
    }
 
    cout << "IMPOSSIBLE";
}
