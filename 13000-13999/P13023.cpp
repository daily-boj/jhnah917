#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> g[2020];
int chk[2020];

void dfs(int v, int dep){
    if(dep == 5){ cout << 1; exit(0); }
    for(auto i : g[v]) if(!chk[i]){
            chk[i] = 1; dfs(i,dep+1); chk[i] = 0;
        }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int s, e; cin >> s >> e; s++; e++;
        g[s].push_back(e);
        g[e].push_back(s);
    }
    for(int i=1; i<=n; i++){
        memset(chk, 0, sizeof chk);
        chk[i] = 1;
        dfs(i, 1);
        chk[i] = 0;
    }
    cout << 0;
}