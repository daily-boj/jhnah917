#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef pair<int, int> p;

int n, m, pv;
vector<p> g[22];
int dst[22], prv[22];

void init(){
    memset(dst, 0x3f, sizeof dst);
    memset(prv, -1, sizeof prv);
    for(auto & i : g) i.clear();
}

void solve(){
    init(); cin >> m >> n;
    for(int i=0; i<m; i++){
        int s, e, x; cin >> s >> e >> x;
        g[s].emplace_back(e, x);
        g[e].emplace_back(s, x);
    }
    priority_queue<p> pq;
    pq.emplace(0, 0); dst[0] = 0;
    while(!pq.empty()){
        int now = pq.top().y;
        int cst = -pq.top().x;
        pq.pop();
        if(cst > dst[now]) continue;
        for(auto i : g[now]){
            if(dst[i.x] > dst[now] + i.y){
                dst[i.x] = dst[now] + i.y;
                pq.emplace(-dst[i.x], i.x);
                prv[i.x] = now;
            }
        }
    }

    cout << "Case #" << ++pv << ": ";
    if(dst[n-1] > 1e9){
        cout << "-1\n"; return;
    }
    stack<int> stk;
    for(int i=n-1; i!=-1; i=prv[i]){
        stk.push(i);
    }
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}