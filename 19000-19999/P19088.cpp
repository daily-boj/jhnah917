#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;
const ll mod = 1e9+7;

int n, q; ll d;
p a[202020]{};
ll pw[202020];
int ins[202020], del[202020], idx[202020];

struct Seg{
    ll tree[2][1u << 19u]{}; //sum, cnt
    unsigned sz = 1u << 18u;
    void merge(unsigned node){
        tree[0][node] = tree[0][node << 1u] * pw[tree[1][node << 1u | 1u]] + tree[0][node << 1u | 1u];
        tree[0][node] %= mod;
        tree[1][node] = tree[1][node << 1u] + tree[1][node << 1u | 1u];
    }
    void build(){
        for(unsigned i=1; i<=n+q; i++) if(a[i].y <= n) tree[0][i|sz] = a[i].x, tree[1][i|sz] = 1;
        for(unsigned i=sz-1; i; i--) merge(i);
    }
    void update(unsigned x){
        x |= sz;
        tree[1][x] = !tree[1][x];
        tree[0][x] = tree[1][x] ? a[x-sz].x : 0;
        while(x >>= 1u) merge(x);
    }
    ll query(){ return tree[0][1]; }
} seg;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> q >> d; pw[0] = 1;
    for(int i=1; i<=n; i++) pw[i] = pw[i-1] * d % mod;
    for(int i=1; i<=n; i++){
        cin >> a[i].x; a[i].y = idx[i] = i;
    }
    for(int i=1; i<=q; i++){
        ll x, y; cin >> x >> y;
        del[i] = idx[x];
        ins[i] = idx[x] = n + i;
        a[n+i] = {y, n + i};
    }
    sort(a+1, a+n+q+1, greater<>());
    for(int i=1; i<=n+q; i++) idx[a[i].y] = i;
    seg.build();
    cout << seg.query() << "\n";
    for(int i=1; i<=q; i++){
        seg.update(idx[del[i]]);
        seg.update(idx[ins[i]]);
        cout << seg.query() << "\n";
    }
}