#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    ll sum = 0;
    vector<ll> x(n);
    for(auto &i: x)
        cin >> i, sum += i;

    vector<ll> memo(sum + 1);
    memo[0] = 1;
    for(ll i = 0; i < n; i++) {
        vector<ll> nw_memo = memo;
        for(ll j = sum - x[i]; j >= 0; j--)
            nw_memo[j + x[i]] |= memo[j];

        swap(memo, nw_memo);
    }

    vector<ll> ans;
    for(ll i = 1; i <= sum; i++)
        if(memo[i])
            ans.push_back(i);

    cout << sz(ans) << '\n';
    for(auto i: ans)
        cout << i << ' ';
}
