#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define sz(x) (ll)(x).size()

struct Node {
    ll tl, tr, sum;
    Node *cle, *cri;

    Node(ll tl, ll tr, vector<ll> &x) : tl(tl), tr(tr), sum(0) {
        if(tl == tr) {
            sum = x[tl];
            return;
        }
        ll tm = tl + (tr - tl) / 2;
        cle = new Node(tl, tm, x);
        cri = new Node(tm + 1, tr, x);
        sum = cle->sum + cri->sum;
    }

    Node(ll tl, ll tr, ll val) : tl(tl), tr(tr), sum(val) {}

    Node(ll tl, ll tr, Node *cle, Node *cri) : tl(tl), tr(tr), cle(cle), cri(cri) {
        sum = cle->sum + cri->sum;
    }

    Node* upd(ll pos, ll val) {
        if(tl == tr) 
            return new Node(tl, tr, val);

        ll tm = tl + (tr - tl) / 2;
        if(pos <= tm)
            return new Node(tl, tr, cle->upd(pos, val), cri);

        return new Node(tl, tr, cle, cri->upd(pos, val));
    }

    ll qry(ll le, ll ri) {
        if(le > ri)
            return 0;

        if(le == tl && ri == tr) 
            return sum;

        ll tm = tl + (tr - tl) / 2;
        return cle->qry(le, min(tm, ri)) + cri->qry(max(tm + 1, le), ri);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n, q;
    cin >> n >> q;

    vector<ll> x(n);
    for(auto &i: x)
        cin >> i;

    vector<Node*> segs({new Node(0, n - 1, x)});
    while(q--) {
        ll t;
        cin >> t;

        if(t == 1) {
            ll k, a, x;
            cin >> k >> a >> x, --k, --a;

            segs[k] = segs[k]->upd(a, x);
            continue;
        }

        if(t == 2) {
            ll k, a, b;
            cin >> k >> a >> b, --k, --a, --b;

            cout << segs[k]->qry(a, b) << '\n';
            continue;
        }

        ll k;
        cin >> k, --k;

        segs.push_back(new Node(0, n - 1, segs[k]->cle, segs[k]->cri));
    }
}
