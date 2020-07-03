#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

struct Node{
    ll l, r, lr, mx;
    void set(ll v){ l = r = lr = 0; mx = v; }
};
void merge(const Node &a, const Node &b, Node &res){
    if(!a.mx){ res = b; return; }
    if(!b.mx){ res = a; return; }
    res.lr = max({a.l + b.lr, a.lr + b.r});
    res.l = max({res.lr, a.l + b.l, a.lr + b.mx});
    res.r = max({res.lr, a.r + b.r, a.mx + b.lr});
    res.mx = max({res.l, res.r, a.r + b.mx, a.mx + b.l});
}

Node tree[1 << 17];
const int sz = 1 << 16;
void update(int x, int v){
    x |= sz; tree[x].set(v);
    while(x >>= 1) merge(tree[x << 1], tree[x << 1 | 1], tree[x]);
}
ll query(){ return tree[1].mx; }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    for(int i=1; i<=n; i++){
        int t; cin >> t; update(i, t);
    }
    ll ans = 0;
    while(q--){
        int a, b; cin >> a >> b;
        update(a, b);
        ans += query();
    }
    cout << ans;
}