#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int n, m;
int a[10101], chk[10101];
vector<p> g[10101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=0; i<m; i++){
        int s, e, x; cin >> x >> s >> e;
        g[s].emplace_back(e, x);
        g[e].emplace_back(s, x);
    }
    memset(chk, 0, sizeof chk);
    for(int t=1; t<=n; t++){
        int idx = -1;
        for(int i=1; i<=n; i++) if(!chk[i]){
                if(idx == -1 || a[idx] > a[i]) idx = i;
            }
        chk[idx] = 1;
        for(auto i : g[idx]){
            a[i.y] = min(a[i.y], a[idx] + a[i.x]);
        }
    }
    cout << a[1];
}