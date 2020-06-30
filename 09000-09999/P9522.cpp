#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n;
int x[10101], y[10101];
int bias = 555;
vector<int> g[2020];

int par[2020], chk[2020];
int x_chk[555], y_chk[555];

int dfs(int v){
    chk[v] = 1;
    for(auto i : g[v]){
        if(chk[i]) continue; chk[i] = 1;
        if(par[i] == -1 || dfs(par[i])){
            par[i] = v; return 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x[i] >> y[i];
        g[x[i]].push_back(y[i]+bias);
        x_chk[x[i]] = y_chk[y[i]] = 1;
    }
    for(int i=0; i<2020; i++) compress(g[i]);

    int match = 0;
    memset(par, -1, sizeof par);
    for(int i=1; i<=500; i++){
        memset(chk, 0, sizeof chk);
        match += dfs(i);
    }

    int a = 0, b = 0;
    for(int i=1; i<=500; i++) a += x_chk[i], b += y_chk[i];
    if(a == match && b == match) cout << "Slavko";
    else cout << "Mirko";
}