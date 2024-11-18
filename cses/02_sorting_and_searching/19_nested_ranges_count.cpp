#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
template<class T>
using ost=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<array<ll, 3>> r;
    for(ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        r.push_back({b, -a, i});
    }
    sort(r.begin(), r.end());

    ost<array<ll, 2>> pbds;
    vector<ll> ans1(n);
    for(auto [b, a, id]: r) {
        ans1[id] = pbds.order_of_key({a, (ll)1e9 + 1});
        pbds.insert({a, id});
    }

    pbds.clear();
    vector<ll> ans2(n);
    reverse(r.begin(), r.end());
    for(auto [b, a, id]: r) {
        a = -a;
        ans2[id] = pbds.order_of_key({a, (ll)1e9 + 1});
        pbds.insert({a, id});
    }

    for(auto i: ans1)
        cout << i << ' ';

    cout << '\n';

    for(auto i: ans2)
        cout << i << ' ';
}
