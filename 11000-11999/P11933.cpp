#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

int n, q;
vector<p> g[505050];
int par[22][505050], dep[505050]; ll dst[505050];
int in[505050], out[505050], pv;

void dfs(int v = 1, int b = -1){
    in[v] = ++pv;
    for(auto i : g[v]) if(i.x != b){
            par[0][pv+1] = in[v];
            dep[pv+1] = dep[in[v]] + 1;
            dst[pv+1] = dst[in[v]] + i.y;
            dfs(i.x, v);
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

int color[505050];
vector<int> vertex;

ll ans = 1e18;
p f(int v){
    ll a = color[v] == 1 ? 0 : 1e18; // min dst(v, S_i)
    ll b = color[v] == 2 ? 0 : 1e18; // min dst(v, T_i)
    color[v] = 0;
    while(pv < vertex.size() && vertex[pv] <= out[v]){
        int nxt = vertex[pv]; pv++;
        auto t = f(nxt);
        a = min(a, t.x + dst[nxt] - dst[v]);
        b = min(b, t.y + dst[nxt] - dst[v]);
    }
    ans = min(ans, a+b);
    return {a, b};
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> q;
    for(int i=1; i<n; i++){
        int s, e, x; cin >> s >> e >> x; s++; e++;
        g[s].emplace_back(e, x);
        g[e].emplace_back(s, x);
    }
    dfs();
    for(int i=1; i<22; i++) for(int j=1; j<=n; j++) par[i][j] = par[i-1][par[i-1][j]];

    while(q--){
        int s, t; cin >> s >> t;
        vertex.clear();
        for(int i=0; i<s; i++){
            int x; cin >> x; x++; vertex.push_back(in[x]); color[in[x]] = 1;
        }
        for(int i=0; i<t; i++){
            int x; cin >> x; x++; vertex.push_back(in[x]); color[in[x]] = 2;
        }
        compress(vertex);
        vector<int> lcaa;
        for(int i=1; i<vertex.size(); i++) lcaa.push_back(lca(vertex[i-1], vertex[i]));
        for(auto i : lcaa) vertex.push_back(i);
        compress(vertex);
        ans = 1e18; pv = 0; f(1);
        cout << ans << "\n";
    }
}