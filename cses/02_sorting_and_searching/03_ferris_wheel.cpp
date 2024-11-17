#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, x;
    cin >> n >> x;

    deque<ll> dq;
    for(ll i = 0; i < n; i++) {
        ll a;
        cin >> a;

        dq.push_back(a);
    }
    sort(dq.begin(), dq.end());

    ll ans = 0;
    while(sz(dq) > 1) {
        if(dq.front() + dq.back() <= x) {
            dq.pop_front();
            dq.pop_back();
            ans++;
            continue;
        }

        dq.pop_back();
        ans++;
    }

    cout << ans + sz(dq);
}
