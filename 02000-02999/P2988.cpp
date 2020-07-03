#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n, a[4][101010];
int chk[101010], cnt[4][101010];
vector<int> g[101010];

int ans;
void dfs(int v){
    for(auto i : g[v]) if(!chk[i]){
            chk[i] = 1; ans++;
            if(!--cnt[1][a[1][i]]) dfs(a[1][i]);
            if(!--cnt[2][a[2][i]]) dfs(a[2][i]);
            if(!--cnt[3][a[3][i]]) dfs(a[3][i]);
        }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=3; i++) for(int j=1; j<=n; j++) cin >> a[i][j], cnt[i][a[i][j]]++, g[a[i][j]].push_back(j);
    for(int i=1; i<=n; i++) if(!cnt[1][i] || !cnt[2][i] || !cnt[3][i]) dfs(i);
    cout << ans;
}