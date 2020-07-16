#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

struct TrieNode{
    int par, ch[26], id;
    TrieNode(){ par = id = 0; memset(ch, 0, sizeof ch); }
};
vector<TrieNode> nd;

int n, q;
string a[202020];
vector< vector<int> > g;
int id[202020];
int par[22][202020], dep[202020], in[202020], out[202020], pv;

vector<int> vertex;
ll ans = 0;

void insert(int node, const string &s, int i, int x){
    if(i == s.size()){ nd[node].id = x; return; }
    int t = s[i] - 'a';
    if(!nd[node].ch[t]){
        nd[node].ch[t] = nd.size();
        nd.emplace_back();
        nd.back().par = node;
    }
    insert(nd[node].ch[t], s, i+1, x);
}

void dfs(int v){
    in[v] = ++pv;
    for(auto i : g[v]){
        dep[pv+1] = dep[in[v]] + 1;
        par[0][pv+1] = in[v];
        dfs(i);
    }
    out[in[v]] = pv;
}

int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    int diff = dep[u] - dep[v];
    for(int i=0; diff; i++){
        if(diff & 1) u = par[i][u];
        diff >>= 1;
    }
    if(u == v) return u;
    for(int i=21; ~i; i--) if(par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
    return par[0][u];
}

int par_edge[202020];
int chk[202020];
int solve(int v, int b){// return subtree's leaf count
    int res = chk[v];
    while(pv < vertex.size() && vertex[pv] <= out[v]){
        int nxt = vertex[pv++];
        par_edge[nxt] = dep[nxt] - dep[v];
        res += solve(nxt, b);
    }
    if(res == b) ans += par_edge[v];
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> q; for(int i=1; i<=n; i++) cin >> a[i];
    nd.emplace_back(); nd.emplace_back();
    for(int i=1; i<=n; i++) insert(1, a[i], 0, i);
    g.resize(nd.size() + 5);
    for(int i=2; i<nd.size(); i++){
        g[nd[i].par].push_back(i);
        if(nd[i].id) id[nd[i].id] = i;
    }
    dfs(1);
    for(int i=1; i<22; i++) for(int j=1; j<nd.size(); j++) par[i][j] = par[i-1][par[i-1][j]];

    while(q--){
        int a, b; cin >> a >> b;
        vertex.clear();
        for(int i=0; i<a; i++){ int t; cin >> t; vertex.push_back(in[id[t]]); chk[in[id[t]]] = 1; }
        sort(all(vertex)); int tmp = vertex.size();
        for(int i=1; i<tmp; i++) vertex.push_back(lca(vertex[i-1], vertex[i]));
        vertex.push_back(1); compress(vertex);
        ans = pv = 0;
        solve(1, b);
        cout << ans << "\n";
        for(auto i : vertex) chk[i] = 0;
    }
}