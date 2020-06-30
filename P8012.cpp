#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define int long long
using namespace std;

int n;
vector<int> g[30303];
int par[22][30303], dep[30303];

void dfs(int v, int p){
    for(auto i : g[v]) if(i != p){
        dep[i] = dep[v] + 1; par[0][i] = v;
        dfs(i, v);
    }
}

int lca(int u, int v){
    if(dep[u] > dep[v]) swap(u, v);
    int diff = dep[v] - dep[u];
    for(int i=0; diff; i++){
        if(diff & 1) v = par[i][v];
        diff >>= 1;
    }
    if(u == v) return u;
    for(int i=21; i>=0; i--){
        if(par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
    }
    return par[0][u];
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<n; i++){
        int s, e; cin >> s >> e;
        g[s].push_back(e);
        g[e].push_back(s);
    }
    dfs(1, -1);
    for(int j=1; j<22; j++) for(int i=1; i<=n; i++) par[j][i] = par[j-1][par[j-1][i]];
    int q; cin >> q;
    int t; cin >> t;
    int ans = 0;
    for(int i=1; i<q; i++){
        int x; cin >> x;
        ans += dep[t] + dep[x] - dep[lca(t, x)] * 2;
        t = x;
    }
    cout << ans;
}