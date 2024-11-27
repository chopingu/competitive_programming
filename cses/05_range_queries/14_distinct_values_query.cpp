#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct chash {
    const uint64_t C=ll(2e18*acos(0))+71;
    const int RANDOM=chrono::high_resolution_clock::now().time_since_epoch().count();
    ll operator()(ll x) const {
        return __builtin_bswap64((x^RANDOM)*C);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, q;
    cin >> n >> q;

    vector<ll> x(n);
    for(auto &i: x)
        cin >> i;

    vector<vector<array<ll, 2>>> qrs(n);
    for(ll i = 0; i < q; i++) {
        ll a, b;
        cin >> a >> b, --a, --b;

        qrs[b].push_back({a, i});
    }

    vector<ll> ft(n + 1);
    auto upd = [&](ll id, ll val) -> void {
        for(++id; id <= n; id += id & -id)
            ft[id] += val;
    };

    auto qry = [&](ll id) -> ll {
        ll ans = 0;
        for(++id; id; id -= id & -id)
            ans += ft[id];

        return ans;
    };

    vector<ll> ans(q);
    gp_hash_table<ll, ll, chash> mp;
    for(ll i = 0; i < n; i++) {
        upd(i, 1);
        if(mp.find(x[i]) == mp.end())
            mp[x[i]] = i;
        else
            upd(mp[x[i]], -1), mp[x[i]] = i;

        for(auto [a, idx]: qrs[i])
            ans[idx] = qry(i) - qry(a - 1);
    }

    for(auto i: ans)
        cout << i << '\n';
}
