#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<ll> t;
    vector<array<ll, 3>> pr;
    for(ll i = 0; i < n; i++) {
        ll a, b, p;
        cin >> a >> b >> p;

        t.push_back(a);
        t.push_back(b);
        pr.push_back({a, b, p});
    }
    sort(t.begin(), t.end());

    map<ll, ll> comp;
    for(auto i: t)
        if(comp.find(i) == comp.end())
            comp[i] = sz(comp);

    n = sz(comp);
    for(auto i: t)
        cout << comp[i] << '\n';
}
