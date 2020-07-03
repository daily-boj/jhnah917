#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
const ll mod = 1e9+7;
const int di[] = {0, 1, 0, -1};
const int dj[] = {-1, 0, 1, 0};

struct Edge{
    int v, c, d;
    Edge(int v, int c, int d) : v(v), c(c), d(d) {}
};

int n, m;
int a[111][111];
int id[111][111], pv;
vector<Edge> g[30303];
const int S = 30301, T = 30302;

void addEdge(int s, int e, int x) {
    g[s].emplace_back(e, x, (int) g[e].size());
    g[e].emplace_back(s, 0, (int) g[s].size() - 1);
}

int lv[30303], work[30303];
bool bfs(){
    memset(lv, -1, sizeof lv);
    queue<int> q; q.push(S); lv[S] = 0;
    while(q.size()){
        int v = q.front(); q.pop();
        for(auto i : g[v]){
            if(lv[i.v] == -1 && i.c){
                lv[i.v] = lv[v] + 1; q.push(i.v);
            }
        }
    }
    return lv[T] != -1;
}
int dfs(int v, int tot){
    if(v == T) return tot;
    for(int &_i=work[v]; _i<g[v].size(); _i++){
        Edge &i = g[v][_i];
        if(lv[i.v] == lv[v] + 1 && i.c){
            int fl = dfs(i.v, min(i.c, tot));
            if(fl){
                i.c -= fl; g[i.v][i.d].c += fl;
                return fl;
            }
        }
    }
    return 0;
}
int dinic(){
    int ret = 0;
    while(bfs()){
        memset(work, 0, sizeof work);
        int t;
        while((t = dfs(S, 1e9))) ret += t;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    set<p> st; st.emplace(2, 3); st.emplace(3, 3); st.emplace(3, 2);
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin >> a[i][j], id[i][j] = ++pv;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
            int c = 0;
            if(a[i][j] < 2){ cout << "HOMELESS"; return 0; }
            if(a[i][j] == 3) c = 1;
            if(a[i][j] == 2) c = 2;
            addEdge(id[i][j] << 1, id[i][j] << 1 | 1, c);
        }
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
            if(i + j & 1){ addEdge(id[i][j] << 1 | 1, T, 10); continue; }
            addEdge(S, id[i][j] << 1, 10);
            for(int k=0; k<4; k++){
                int ii = i + di[k], jj = j + dj[k];
                if(ii < 1 || jj < 1 || ii > n || jj > m) continue;
                if(!st.count(p(a[i][j], a[ii][jj]))) continue;
                addEdge(id[i][j] << 1 | 1, id[ii][jj] << 1, 1);
            }
        }
    dinic();
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
            int t = id[i][j];
            for(auto k : g[t << 1]) if(k.v == (t<<1|1)){
                    if(k.c != 0){ cout << "HOMELESS"; return 0; }
                }
        }
    cout << "HAPPY";
}