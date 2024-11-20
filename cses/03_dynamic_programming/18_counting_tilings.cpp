#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;

    const ll mod = 1e9 + 7;
    vector<ll> memo(1 << n);
    memo[(1 << n) - 1] = 1;
    for(ll i = 0; i < m; i++) {
        vector<ll> nw_memo(1 << n);

        auto rec = [&](const ll bitmask, ll id, ll nw_bitmask, auto&& rec) -> void {
            if(id > n)
                return;

            if(id == n) {
                nw_memo[nw_bitmask] += memo[bitmask];
                nw_memo[nw_bitmask] %= mod;
                return;
            }

            if(id < n - 1 && bitmask & (1 << id) && bitmask & (1 << (id + 1))) 
                rec(bitmask, id + 2, nw_bitmask | (1 << id) | (1 << (id + 1)), rec);

            if(!(bitmask & (1 << id)))
                rec(bitmask, id + 1, nw_bitmask | (1 << id), rec);

            if(bitmask & (1 << id))
                rec(bitmask, id + 1, nw_bitmask, rec);
        };

        for(ll j = 0; j < (1 << n); j++)
            rec(j, 0, 0, rec);

        swap(memo, nw_memo);
    }

    cout << memo[(1 << n) - 1];
}
