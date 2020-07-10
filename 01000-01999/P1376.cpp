#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int n, m;
vector<p> edge;
vector<int> g[101010];

struct Seg{
    int cnt, sz;
    vector<int> tree, mx;
    void init(int v){
        sz = 2; cnt = g[v].size();
        while(sz < cnt*2) sz <<= 1;
        tree.resize(sz); mx.resize(sz); sz >>= 1;
        for(int i=0; i<cnt; i++) tree[i|sz] = 1, mx[i|sz] = g[v][i];
        for(int i=sz-1; i; i--){
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
            mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
        }
    }
    int even(){
        int node = 1;
        while(node < sz){
            if(tree[node << 1]) node = node * 2;
            else node = node * 2 + 1;
        }
        return mx[node];
    }
    int odd(){
        int node = 1, k = (tree[1] + 1) / 2;
        while(node < sz){
            if(tree[node << 1] >= k) node = node * 2;
            else k -= tree[node << 1], node = node * 2 + 1;
        }
        return mx[node];
    }
    int query(){
        if(tree[1] & 1) return odd();
        return even();
    }
    void erase(int x){
        int node = 1;
        while(node < sz){
            if(mx[node << 1] >= x) node = node * 2;
            else node = node * 2 + 1;
        }
        if(mx[node] != x) return;
        x = node;
        tree[x] = mx[x] = 0;
        while(x >>= 1){
            tree[x] = tree[x << 1] + tree[x << 1 | 1];
            mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
        }
    }
} seg[101010];

int chk[101010];

void dfs(int v){
    chk[v] = 1;
    cout << v << " ";
    while(1){
        int t = seg[v].query();
        if(!t) break;
        for(auto i : g[t]) seg[i].erase(t);
        dfs(t);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int s, e; cin >> s >> e;
        if(s == e) continue;
        if(s > e) swap(s, e);
        edge.emplace_back(s, e);
    }
    compress(edge);
    for(auto i : edge) g[i.x].push_back(i.y), g[i.y].push_back(i.x);
    for(int i=1; i<=n; i++) sort(all(g[i]));
    for(int i=1; i<=n; i++) seg[i].init(i);

    for(auto i : g[1]) seg[i].erase(1);
    dfs(1);
}