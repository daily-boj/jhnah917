#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

const ll inf = 1e18;

struct Line{
    ll a, b;
    ll f(ll x){ return a*x+b; }
    Line(ll a, ll b) : a(a), b(b) {}
    Line() : Line(0, -inf) {}
};

struct Node{
    Node() : l(-1), r(-1), v(0, -inf) {}
    int l, r; Line v;
};
vector<Node> nd;

void update(int node, ll s, ll e, Line v){
    Line lo = nd[node].v, hi = v;
    if(lo.f(s) > hi.f(s)) swap(lo, hi);
    if(lo.f(e) <= hi.f(e)){ nd[node].v = hi; return; }
    ll m = s + e >> 1;
    if(lo.f(m) <= hi.f(m)){
        nd[node].v = hi;
        if(nd[node].r == -1) nd[node].r = nd.size(), nd.emplace_back();
        update(nd[node].r, m+1, e, lo);
    }else{
        nd[node].v = lo;
        if(nd[node].l == -1) nd[node].l = nd.size(), nd.emplace_back();
        update(nd[node].l, s, m, hi);
    }
}

ll query(int node, ll s, ll e, ll x){
    if(node == -1) return -inf;
    ll t = nd[node].v.f(x);
    ll m = s + e >> 1;
    if(x <= m) return max(t, query(nd[node].l, s, m, x));
    else return max(t, query(nd[node].r, m+1, e, x));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    const ll range = 2e12;
    nd.emplace_back();
    while(q--){
        ll op, a, b; cin >> op >> a;
        if(op == 1){
            cin >> b;
            update(0, -range, range, {a, b});
        }
        else cout << query(0, -range, range, a) << "\n";
    }
}