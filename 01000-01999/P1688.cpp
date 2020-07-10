#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

#define x first
#define y second
typedef long long ll;
typedef pair<ll, ll> p;
istream& operator >> (istream &in, p &t){ in >> t.x >> t.y; return in; }
ostream& operator << (ostream &out, p t){ out << t.x << t.y; return out; }
p operator + (p a, p b){ return p(a.x + b.x, a.y + b.y); }
p operator - (p a, p b){ return p(a.x - b.x, a.y - b.y); }

inline ll _ccw(const p &a, const p &b){ return a.x*b.y - b.x*a.y; }
inline ll _ccw(const p &a, const p &b, const p &c){ return _ccw(b-a, c-b); }
inline ll area(const p &a, const p &b, const p &c){ return abs(_ccw(a, b, c)); }
inline int ccw(const p &a, const p &b, const p &c){
    ll cw = _ccw(a, b, c);
    if(cw > 0) return 1;
    if(cw) return -1;
    return 0;
}
inline ll dst(const p &a, const p &b){
    ll dx = b.x - a.x, dy = b.y - a.y;
    return dx*dx + dy*dy;
}

bool segment_crash(p a, p b, p c, p d){
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if(!ab && !cd){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}
const ll MAX_COORD = 1e9;
bool pip(const vector<p> &v, p p1){
    int n = v.size(), cnt = 0;
    p p2 = p(MAX_COORD+1, p1.y+1);
    for(int i=0; i<n; i++){
        int j = i+1 == n ? 0 : i+1;
        if(!ccw(v[i], v[j], p1) && min(v[i], v[j]) <= p1 && p1 <= max(v[i], v[j])) return 1;
        cnt += segment_crash(v[i], v[j], p1, p2);
    }
    return cnt & 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n; vector<p> v(n);
    for(auto &i : v) cin >> i;
    for(int i=0; i<3; i++){
        p t; cin >> t;
        cout << pip(v, t) << "\n";
    }
}