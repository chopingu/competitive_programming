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

    ost<ll> pbds;
    for(ll i = 1; i <= n; i++)
        pbds.insert(i);

    ll cur = 0;
    while(sz(pbds)) {
        cur += k, cur %= sz(pbds);
        auto it = pbds.find_by_order(cur);
        cout << *it << ' ';
        pbds.erase(it);
    }
}
