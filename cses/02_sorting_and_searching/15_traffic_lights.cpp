#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll x, n;
    cin >> x >> n;

    multiset<ll> lens;
    lens.insert(x);

    set<array<ll, 2>> s;
    s.insert({0, x});

    for(ll i = 0; i < n; i++) {
        ll p;
        cin >> p;

        auto it = s.upper_bound({p, (ll)-1e9});
        --it;

        auto [a, b] = *it;
        s.erase(it);
        lens.erase(lens.find(b - a));
        s.insert({a, p});
        s.insert({p, b});
        lens.insert(p - a);
        lens.insert(b - p);

        cout << *lens.rbegin() << ' ';
    }
}
