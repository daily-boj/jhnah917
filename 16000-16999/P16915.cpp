#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n, m;
vector<int> g[202020], r[202020], dfn;
int chk[202020], pv;

void dfs(int v){
    chk[v] = 1;
    for(auto i : g[v]) if(!chk[i]) dfs(i);
    dfn.push_back(v);
}
void rdfs(int v, int color){
    chk[v] = color;
    for(auto i : r[v]) if(!chk[i]) rdfs(i, color);
}
void getSCC(){
    for(int i=1; i<=m; i++){
        if(!chk[i << 1]) dfs(i << 1);
        if(!chk[i << 1 | 1]) dfs(i << 1 | 1);
    }
    reverse(all(dfn)); memset(chk, 0, sizeof chk);
    for(auto i : dfn) if(!chk[i]) rdfs(i, ++pv);
}

void addEdge(int a, int b){
    if(a > 0) a = a * 2;
    else a = (-a) * 2 + 1;
    if(b > 0) b = b * 2;
    else b = (-b) * 2 + 1;
    g[a].push_back(b);
    r[b].push_back(a);
}

int a[101010];
vector<int> t[101010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=m; i++){
        int cnt; cin >> cnt;
        for(int j=1; j<=cnt; j++){
            int x; cin >> x; t[x].push_back(i);
        }
    }
    for(int i=1; i<=n; i++){
        if(t[i].empty()){
            if(!a[i]){ cout << 0; return 0; }
            continue;
        }
        if(t[i].size() == 1){
            if(a[i]) addEdge(t[i][0], -t[i][0]);
            else addEdge(-t[i][0], t[i][0]);
            continue;
        }
        int a = t[i][0], b = t[i][1];
        if(::a[i]){
            addEdge(a, b); addEdge(-a, -b);
            addEdge(b, a); addEdge(-b, -a);
        }else{
            addEdge(-a, b); addEdge(-b, a);
            addEdge(a, -b); addEdge(b, -a);
        }
    }
    getSCC();
    for(int i=1; i<=m; i++){
        if(chk[i << 1] == chk[i << 1 | 1]){
            cout << 0;return 0;
        }
    }
    cout << 1;
}