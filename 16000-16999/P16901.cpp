#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
const int MXD = 30;

struct Node{
    int l, r;
    Node() : Node(-1, -1) {}
    Node(int l, int r) : l(l), r(r) {}
};
vector<Node> nd;

int n;
int a[202020];

void insert(int x, int node = 1, int dep = MXD){
    if(dep == -1) return;
    if((x >> dep) & 1){
        if(nd[node].r == -1) nd[node].r = nd.size(), nd.emplace_back();
        insert(x, nd[node].r, dep-1);
    }else{
        if(nd[node].l == -1) nd[node].l = nd.size(), nd.emplace_back();
        insert(x, nd[node].l, dep-1);
    }
}
// get min
int query(int x, int node = 1, int dep = MXD){
    if(dep == -1) return 0;
    if((x >> dep) & 1){
        if(nd[node].r != -1) return query(x, nd[node].r, dep-1);
        return (1 << dep) + query(x, nd[node].l, dep-1);
    }else{
        if(nd[node].l != -1) return query(x, nd[node].l, dep-1);
        return (1 << dep) + query(x, nd[node].r, dep-1);
    }
}

ll ans = 0;
void solve(int s, int e, int dep = MXD){
    if(dep == -1 || s >= e) return;

    int m = s; ll res = 1e18;
    while(m <= e && !(a[m] & (1 << dep))) m++; m--;
    solve(s, m, dep-1); solve(m+1, e, dep-1);

    if(s > m || m+1 > e) return;
    nd.clear(); nd.resize(2);
    for(int i=s; i<=m; i++) insert(a[i]);
    for(int i=m+1; i<=e; i++) res = min<ll>(res, query(a[i]));
    ans += res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n; for(int i=1; i<=n; i++) cin >> a[i]; sort(a+1, a+n+1);
    solve(1, n);
    cout << ans;
}