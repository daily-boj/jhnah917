#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int par[1010101];
int find(int v){ return v == par[v] ? v : par[v] = find(par[v]); }
void merge(int u, int v){ u = find(u); v = find(v); if(u != v) par[u] = v; }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m; iota(par, par+1010101, 0);
    while(m--){
        int op, a, b; cin >> op >> a >> b;
        if(!op) merge(a, b);
        else if(find(a) == find(b)) cout << "YES\n";
        else cout << "NO\n";
    }
};