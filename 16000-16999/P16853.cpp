#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

map<string, int> mp;

void init(){
    mp["BLACK"] = 0; mp["RED"] = 1; mp["GREEN"] = 2; mp["YELLOW"] = 3;
    mp["BLUE"] = 4; mp["PURPLE"] = 5; mp["CYAN"] = 6; mp["WHITE"] = 7;
}

int n, m;
vector<int> g[303030], r[303030], dfn;
int chk[303030], pv;
inline int f(int i, int x){ return 3*x-(2-i); }
void addEdge(int a, int b){
    a = a > 0 ? a * 2 : (-a) * 2 + 1;
    b = b > 0 ? b * 2 : (-b) * 2 + 1;
    g[a].push_back(b);
    r[b].push_back(a);
}
inline void addCNF(int a, int b){ addEdge(-a, b); addEdge(-b, a); }
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
    for(int i=1; i<=3*n; i++){
        if(!chk[i << 1]) dfs(i << 1);
        if(!chk[i << 1 | 1]) dfs(i << 1 | 1);
    }
    reverse(all(dfn)); memset(chk, 0, sizeof chk);
    for(auto i : dfn) if(!chk[i]) rdfs(i, ++pv);
}

void valid(string s1, string s2){
    int a = mp[s1], b = mp[s2];
    if(!(a & 1) && (b & 1)){ cout << "THINKINGFACE"; exit(0); }
    if(!(a & 2) && (b & 2)){ cout << "THINKINGFACE"; exit(0); }
    if(!(a & 4) && (b & 4)){ cout << "THINKINGFACE"; exit(0); }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    init();
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int a, b; char c; string d, e; cin >> a >> b >> c >> d >> e;
        valid(d, e);
        int t = mp[e], tt = mp[d];
        for(int j=0; j<3; j++){
            if(!(tt & (1 << j))) continue;
            if(c == 'H'){
                if(t & (1 << j)) addCNF(f(j, a), f(j, a)), addCNF(f(j, b), f(j, b));
                else addCNF(-f(j, a), -f(j, b));
            }else{
                if(t & (1 << j)) addCNF(f(j, a), f(j, b));
                else addCNF(-f(j, a), -f(j, a)), addCNF(-f(j, b), -f(j, b));
            }
        }
    }
    getSCC();
    for(int i=1; i<=3*n; i++){
        if(chk[i << 1] == chk[i << 1 | 1]){ cout << "THINKINGFACE"; return 0; }
    }
    cout << "ALIEN";
}