#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    auto rec = [&](int cur, int aux, int tar, int rem, auto&& rec) -> void {
        if(!rem)
            return;

        rec(cur, tar, aux, rem - 1, rec);
        cout << cur << ' ' << tar << '\n';
        rec(aux, cur, tar, rem - 1, rec);
    };

    cout << (1 << n) - 1 << '\n';
    rec(1, 2, 3, n, rec);
}
