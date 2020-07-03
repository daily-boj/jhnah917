#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n, g[55][55], cnt;
bool chk[55];
vector<int> comp;

void dfs(int v, int l, int r, int flag){
    cnt++; chk[v] = 1;
    for(int i=1; i<=n; i++){
        if(flag) if(!chk[i] && l <= g[v][i] && g[v][i] <= r) dfs(i, l, r, flag);
        if(!flag) if(!chk[i] && l <= g[i][v] && g[i][v] <= r) dfs(i, l, r, flag);
    }
}

int valid(int l, int r){
    memset(chk, 0, sizeof chk); cnt = 0;
    dfs(1, l, r, 0);
    if(cnt != n) return 0;
    memset(chk, 0, sizeof chk); cnt = 0;
    dfs(1, l, r, 1);
    return cnt == n;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n; comp.reserve(n*n);
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin >> g[i][j], comp.push_back(g[i][j]);
    compress(comp);

    int mn = 1e9+7, l = 0, r = 0;
    for(; r<comp.size(); r++) for(; l<=r; l++){
            if(valid(comp[l], comp[r])) mn = min(mn, comp[r] - comp[l]);
            else break;
        }
    cout << mn;
}