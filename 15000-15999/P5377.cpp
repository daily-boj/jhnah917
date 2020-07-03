#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;
istream& operator >> (istream &in, p &t){ in >> t.x >> t.y; return in; }
ostream& operator << (ostream &out, p t){ out << t.x << " " << t.y; return out; }
p operator - (p a, p b){ return p(a.x - b.x, a.y - b.y); }

int n;
vector<p> v;

int ccw(const p &a, const p &b, const p &c){
    ll dx1 = b.x - a.x, dy1 = b.y - a.y;
    ll dx2 = c.x - b.x, dy2 = c.y - b.y;
    ll res = dx1*dy2 - dx2*dy1;
    if(res > 0) return 1;
    if(res) return -1;
    return 0;
}
ll dst(const p &a, const p &b){
    ll dx = a.x - b.x, dy = a.y - b.y;
    return dx*dx + dy*dy;
}
int cross(p a, p b, p c, p d){
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if(!ab && !cd){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}

vector<p> convexHull(){
    vector<p> ret;
    swap(v[0], *min_element(all(v)));
    sort(v.begin()+1, v.end(), [&](const p &a, const p &b){
        auto cw = ccw(v[0], a, b);
        if(cw) return cw > 0;
        return dst(v[0], a) < dst(v[0], b);
    });
    for(const auto &i : v){
        while(ret.size() >= 2 && ccw(ret[ret.size()-2], ret.back(), i) <= 0) ret.pop_back();
        ret.push_back(i);
    }
    return ret;
}

p st, ed;
int valid(p t){
    int flag = 0;
    for(int i=0; i<n; i++){
        int j = i + 1; if(j == n) j = 0;
        if(ccw(v[i], v[j], st) <= 0) flag = 1;
    }
    return flag;
}

int nxt(int x){ return x+1 == n ? 0 : x+1; }
int prv(int x){ return x == 0 ? n-1 : x-1; }

void solve(){
    cin >> st >> ed >> n; v.resize(n); for(auto &i : v) cin >> i;
    v = convexHull(); n = v.size();
    if(!valid(st)){ cout << "IMPOSSIBLE\n"; return; }
    if(!valid(ed)){ cout << "IMPOSSIBLE\n"; return; }
    v.push_back(st); v.push_back(ed);
    v = convexHull(); n = v.size();
    int i, j;
    for(i=1; i<=n&&ccw(v[i-1], v[i%n], st)>0; i++);
    for(j=1; j<=n&&ccw(v[j-1], v[j%n], ed)>0; j++);
    if(i == j || i > n || j > n){ cout << fixed; cout.precision(3); cout << sqrt(dst(st, ed)) << "\n"; return; }
    i %= n; j %= n;
    double t1, t2;
    t1 = sqrt(dst(st, v[i])) + sqrt(dst(ed, v[prv(j)]));
    t2 = sqrt(dst(st, v[prv(i)])) + sqrt(dst(ed, v[j]));
    for(int k=i; k!=prv(j); k=nxt(k)) t1 += sqrt(dst(v[k], v[nxt(k)]));
    for(int k=j; k!=prv(i); k=nxt(k)) t2 += sqrt(dst(v[k], v[nxt(k)]));
    cout << fixed; cout.precision(3); cout << min(t1, t2) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}