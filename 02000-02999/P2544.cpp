#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n, m, k;
int a[333][333];

namespace Bipartite{
    vector<int> g[333];
    int dst[333], l[333], r[333], chk[333];
    void clear(){ for(int i=0; i<333; i++) g[i].clear(); }
    void addEdge(int s, int e){ g[s].push_back(e); }
    int bfs(){
        queue<int> q; int ret = 0;
        memset(dst, 0, sizeof dst);
        for(int i=1; i<=n; i++) if(l[i] == -1 && !dst[i]){
                q.push(i); dst[i] = 1;
            }
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(auto i : g[v]){
                if(r[i] == -1) ret = 1;
                else if(!dst[r[i]]){
                    dst[r[i]] = dst[v] + 1;
                    q.push(r[i]);
                }
            }
        }
        return ret;
    }
    int dfs(int v){
        if(chk[v]) return 0;
        chk[v] = 1;
        for(auto i : g[v]){
            if(r[i] == -1 || !chk[r[i]] && dst[r[i]] == dst[v] + 1 && dfs(r[i])){
                l[v] = i; r[i] = v; return 1;
            }
        }
        return 0;
    }
    int match(){
        memset(l, -1, sizeof l);
        memset(r, -1, sizeof r);
        int ret = 0;
        while(bfs()){
            memset(chk, 0, sizeof chk);
            for(int i=1; i<=n; i++) if(l[i] == -1 && dfs(i)) ret++;
        }
        return ret;
    }
    int track[666];
    void rdfs(int v){
        if(track[v]) return;
        track[v] = 1;
        for(auto i : g[v]){
            track[i+n] = 1; rdfs(r[i]);
        }
    }
    vector<int> getCover(){
        match();
        memset(track, 0, sizeof track);
        for(int i=1; i<=n; i++) if(l[i] == -1) rdfs(i);
        vector<int> ret;
        for(int i=1; i<=n; i++) if(!track[i]) ret.push_back(i);
        for(int i=n+1; i<=n+m; i++) if(track[i]) ret.emplace_back(i);
        return ret;
    }
}
using namespace Bipartite;

vector<int> tracking(int ans){
    int mxi[333] = {0}, mxj[333] = {0};
    clear();
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) if(a[i][j] > ans) addEdge(i, j);
    auto ret = getCover();
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
            mxi[i] = max(mxi[i], a[i][j]);
            mxj[j] = max(mxj[j], a[i][j]);
        }
    for(int i=1; i<=n; i++) if(mxi[i] <= ans && track[i] && ret.size() < k) ret.push_back(i);
    for(int j=1; j<=m; j++) if(mxj[j] <= ans && !track[j+n] && ret.size() < k) ret.push_back(j+n);
    return ret;
}

int f(int x){
    clear();
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) if(a[i][j] > x) addEdge(i, j);
    return match();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin >> a[i][j];
    int l = 0, r = 505050;
    while(l < r){
        int m = l + r >> 1;
        if(f(m) <= k) r = m;
        else l = m + 1;
    }
    cout << r << "\n";
    auto t = tracking(r);
    vector<int> a, b;
    for(auto i : t){
        if(i <= n) a.push_back(i);
        else b.push_back(i);
    }
    assert(t.size() == k);
    sort(all(a)); sort(all(b));
    cout << a.size() << " "; for(auto i : a) cout << i << " "; cout << "\n";
    cout << b.size() << " "; for(auto i : b) cout << i-n << " "; cout << "\n";
}