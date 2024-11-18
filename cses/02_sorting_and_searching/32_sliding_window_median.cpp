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

    ll n, k;
    cin >> n >> k;

    vector<ll> x(n);
    for(auto &i: x)
        cin >> i;

    ost<array<ll, 2>> pbds;
    for(ll i = 0; i < k; i++)
        pbds.insert({x[i], i});

    cout << (*pbds.find_by_order((k - 1) / 2))[0] << ' ';
    for(ll i = k; i < n; i++) {
        pbds.erase({x[i - k], i - k});
        pbds.insert({x[i], i});

        cout << (*pbds.find_by_order((k - 1) / 2))[0] << ' ';
    }
}
