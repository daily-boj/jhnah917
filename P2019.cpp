#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;
istream& operator >> (istream &in, p &t){ in >> t.x >> t.y; return in; }

struct Line{
    p s, e; int x;
};

ll ccw(const p &a, const p &b, const p &c){
    ll dx1 = b.x - a.x, dy1 = b.y - a.y;
    ll dx2 = c.x - b.x, dy2 = c.y - b.y;
    return dx1*dy2 - dx2*dy1;
}
int cross(p a, p b, p c, p d){
    ll ab = ccw(a, b, c) * ccw(a, b, d);
    ll cd = ccw(c, d, a) * ccw(c, d, b);
    if(!ab && !cd){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}

int n, pv;
Line v[111];
int deg[111], chk[111];
vector<int> g[111];
vector<int> comp[111];

void dfs(int v){
    chk[v] = 1; comp[pv].push_back(v);
    for(auto i : g[v]) if(!chk[i]) dfs(i);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> v[i].s >> v[i].e, v[i].x = i;
        if(v[i].s > v[i].e) swap(v[i].s, v[i].e);
    }
    for(int i=1; i<=n; i++) for(int j=1; j<i; j++){
        if(v[i].s == v[j].s || v[i].s == v[j].e || v[i].e == v[j].s || v[i].e == v[j].e){
            g[i].push_back(j); g[j].push_back(i); deg[i]++; deg[j]++;
        }
    }
    for(int i=1; i<=n; i++) if(!chk[i]) pv++, dfs(i);
    int ans = 0;
    for(int i=1; i<=pv; i++){
        int flag = 1;
        for(auto j : comp[i]) if(deg[j] != 2) flag = 0;
        for(auto j : comp[i]) for(auto k : comp[i]) if(j != k){
            if(v[k].s == v[j].s || v[k].s == v[j].e || v[k].e == v[j].s || v[k].e == v[j].e) continue;
            if(cross(v[j].s, v[j].e, v[k].s, v[k].e)) flag = 0;
        }
        ans += flag;
    }
    cout << ans;
}