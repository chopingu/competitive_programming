#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

struct Q {
    ll k, sumle, sumri;
    multiset<ll> le, ri;

    Q(ll k) : k(k), sumle(0), sumri(0) {}

    void add(ll val) {
        if(!sz(le)) {
            le.insert(val);
            sumle += val;
            return;
        }
        if(val <= *le.rbegin()) {
            le.insert(val);
            sumle += val;
            if(sz(le) > (k + 1) / 2) {
                auto it = le.rbegin();
                ri.insert(*it);
                sumri += *it;
                sumle -= *it;
                le.erase(le.find(*it));
            }
            return;
        }
        ri.insert(val);
        sumri += val;
        if(sz(ri) > k / 2) {
            auto it = ri.begin();
            le.insert(*it);
            sumle += *it;
            sumri -= *it;
            ri.erase(it);
        }
    }

    void remove(ll val) {
        if(val <= *le.rbegin()) {
            le.erase(le.find(val));
            sumle -= val;
            if(sz(le) < (k + 1) / 2) {
                auto it = ri.begin();
                le.insert(*it);
                sumle += *it;
                sumri -= *it;
                ri.erase(it);
            }
            return;
        }
        ri.erase(ri.find(val));
        sumri -= val;
        if(sz(ri) < k / 2) {
            auto it = le.rbegin();
            ri.insert(*it);
            sumri += *it;
            sumle -= *it;
            le.erase(le.find(*it));
        }
    }

    ll qry() {
        return sumri - sumle + (k & 1) * (*le.rbegin());
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, k;
    cin >> n >> k;

    vector<ll> x(n);
    for(auto &i: x)
        cin >> i;

    Q q(k);
    for(ll i = 0; i < k; i++) 
        q.add(x[i]);

    cout << q.qry() << ' ';
    for(ll i = k; i < n; i++) {
        q.add(x[i]);
        q.remove(x[i - k]);
        cout << q.qry() << ' ';
    }
}
