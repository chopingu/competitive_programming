#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    const ll mod = 1e9 + 7;

    ll t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;

        ll memo[n + 1][6]{};
        memo[0][0] = 1;
        for(ll i = 1; i <= n; i++) {
            memo[i][0] += memo[i - 1][0];
            memo[i][0] += memo[i - 1][1];
            memo[i][0] += memo[i - 1][5];

            for(ll j = 0; j < 5; j++)
                memo[i][1] += memo[i - 1][j];

            memo[i][2] += memo[i - 1][0];
            memo[i][2] += memo[i - 1][1];
            memo[i][2] += memo[i - 1][2];
            memo[i][2] += memo[i - 1][3];
        }
    }
}

/*
_ _ 
_ _ 
 |
_
 |
  _
 |

 |

[]

*/
