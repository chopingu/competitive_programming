#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

int main() {
    cin.tie(0)->sync_with_stdio(0);

    struct Node {
        vector<ll> nxt;
        bool out;

        Node() : out(0) {
            nxt.assign(26, -1);
        }
    };

    vector<Node> trie(1);

    auto ins = [&](string s) -> void {
        ll id = 0;
        for(auto ch: s) {
            ll c = ch - 'a';
            if(trie[id].nxt[c] == -1) {
                trie[id].nxt[c] = sz(trie);
                trie.emplace_back();
            }
            id = trie[id].nxt[c];
        }
        trie[id].out = 1;
    };

    string s;
    cin >> s;

    ll k;
    cin >> k;

    for(ll i = 0; i < k; i++) {
        string a;
        cin >> a;

        ins(a);
    }

    const ll mod = 1e9 + 7;

    vector<ll> memo(sz(s), -1);
    auto dp = [&](ll id, auto&& dp) -> ll {
        if(id == sz(s))
            return 1;

        ll &ans = memo[id];
        if(ans ^ -1)
            return ans;

        ans = 0;
        ll cur = 0;
        for(ll i = id; i < sz(s); i++) {
            if(trie[cur].nxt[s[i] - 'a'] == -1) 
                break;

            cur = trie[cur].nxt[s[i] - 'a'];
            if(trie[cur].out)
                ans += dp(i + 1, dp), ans %= mod;
        }

        return ans;
    };

    cout << dp(0, dp);
}
