#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> p;

struct UF{
    int par[101010];
    int rnk[101010];
    vector<p> roll;
    void init(){ iota(par, par+101010, 0); fill(rnk, rnk+101010, 1); }
    int find(int v){ return v == par[v] ? v : find(par[v]); }
    bool merge(int u, int v){
        u = find(u), v = find(v);
        if(u == v) return 0;
        if(rnk[u] > rnk[v]) swap(u, v);
        par[u] = v;
        if(rnk[u] == rnk[v]) rnk[v]++;
        roll.push_back({u, v});
        return 1;
    }
    void undo(int x){
        for(int i=0; i<x; i++){
            if(roll.empty()) exit(-1);
            int u = roll.back().x, v = roll.back().y;
            roll.pop_back();
            par[u] = u;
            if(rnk[u] == rnk[v]+1) rnk[v]--;
        }
    }
} uf[10];

struct Query{
    int op, s, e, x;
    void input(){
        cin >> op >> s >> e;
        if(op == 0) cin >> x;
        if(s > e) swap(s, e);
    }
};

int n, m;
vector<int> tree[1 << 18];
Query qry[101010];
map<p, int> mp;

void update(int node, int s, int e, int l, int r){
    if(r < s || e < l) return;
    if(l <= s && e <= r){ tree[node].push_back(l); return; }
    int m = s + e >> 1;
    update(node << 1, s, m, l, r);
    update(node << 1 | 1, m+1, e, l, r);
}

int cnt[1 << 18][10];
void dfs(int node, int s, int e){
    for(auto i : tree[node]){
        int s = qry[i].s, e = qry[i].e, x = qry[i].x;
        for(int j=x; j<10; j++) cnt[node][j] += uf[j].merge(s, e);
    }
    if(s == e && qry[s].op == 2){
        int u = qry[s].s, v = qry[s].e, flag = 1;
        for(int i=0; i<10; i++) if(uf[i].find(u) == uf[i].find(v)){
                cout << i << "\n"; flag = 0; break;
            }
        if(flag){ cout << "-1\n"; }
    }
    if(s ^ e){
        int m = s + e >> 1;
        dfs(node << 1, s, m);
        dfs(node << 1 | 1, m+1, e);
    }
    for(int i=0; i<10; i++) uf[i].undo(cnt[node][i]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++) qry[i].input();
    for(int i=0; i<m; i++){
        int op = qry[i].op, s = qry[i].s, e = qry[i].e;
        if(op == 0) mp[{s, e}] = i;
        if(op == 1){
            int t = mp[{s, e}];
            update(1, 0, m-1, t, i);
            mp.erase({s, e});
        }
    }
    for(auto i : mp) update(1, 0, m-1, i.y, m-1);
    for(int i=0; i<10; i++) uf[i].init();
    dfs(1, 0, m-1);
}