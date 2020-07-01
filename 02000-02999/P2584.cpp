#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
using namespace std;

typedef pair<int, int> p;

int n, k;
vector<p> g[1010];
int sz[1010], res[1010];
int dp[2][1010][1010];
p prv[2][1010][1010];

int tmp[2][1010];

void dfs(int v, int b){
    sz[v] = 1;
    for(auto i : g[v]) if(i.x != b){
            dfs(i.x, v);
            memset(tmp[0], 0x3f, sizeof(int) * (sz[v]+sz[i.x]+1));
            memset(tmp[1], 0x3f, sizeof(int) * (sz[v]+sz[i.x]+1));
            for(int j=0; j<=sz[v]; j++) for(int k=0; k<=sz[i.x]; k++){
                    if(tmp[0][j+k] > dp[0][v][j] + dp[0][i.x][k] + i.y){
                        tmp[0][j+k] = dp[0][v][j] + dp[0][i.x][k] + i.y;
                        prv[0][i.x][j+k] = {k, 0};
                    }
                    if(tmp[0][j+k] > dp[0][v][j] + dp[1][i.x][k]){
                        tmp[0][j+k] = dp[0][v][j] + dp[1][i.x][k];
                        prv[0][i.x][j+k] = {k, 1};
                    }
                    if(tmp[1][j+k] > dp[1][v][j] + dp[0][i.x][k]){
                        tmp[1][j+k] = dp[1][v][j] + dp[0][i.x][k];
                        prv[1][i.x][j+k] = {k, 0};
                    }
                    if(tmp[1][j+k] > dp[1][v][j] + dp[1][i.x][k] + i.y){
                        tmp[1][j+k] = dp[1][v][j] + dp[1][i.x][k] + i.y;
                        prv[1][i.x][j+k] = {k, 1};
                    }
                }
            sz[v] += sz[i.x];
            memmove(dp[0][v], tmp[0], sizeof(int) * (sz[v]+1));
            memmove(dp[1][v], tmp[1], sizeof(int) * (sz[v]+1));
        }
}

void track(int v, int b, int k, int flag){
    res[v] = flag;
    reverse(all(g[v]));
    for(auto i : g[v]) if(i.x != b){
            sz[v] -= sz[i.x];
            auto t = prv[flag][i.x][k]; k -= t.x;
            track(i.x, v, t.x, t.y);
        }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k;
    for(int i=1; i<n; i++){
        int s, e, x; cin >> s >> e >> x;
        g[s].emplace_back(e, x);
        g[e].emplace_back(s, x);
    }
    for(int i=1; i<=n; i++) dp[1][i][0] = dp[0][i][1] = 1e9+7;
    dfs(1, -1);
    int mn = min(dp[0][1][k], dp[1][1][k]);
    cout << mn << "\n";
    track(1, -1, k, mn == dp[1][1][k]);
    for(int i=1; i<=n; i++) if(res[i]) cout << i << " ";
}