#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

int ccw(const p &a, const p &b, const p &c){
    ll dx1 = b.x - a.x, dy1 = b.y - a.y;
    ll dx2 = c.x - b.x, dy2 = c.y - b.y;
    ll res = dx1*dy2 - dx2*dy1;
    if(res > 0) return 1;
    if(res) return -1;
    return 0;
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

ll dst(const p &a, const p &b){
    ll dx = a.x - b.x, dy = a.y - b.y;
    return dx*dx + dy*dy;
}

int n, q;
vector<p> v;

vector<p> getConvexHull(){
    swap(v[0], *min_element(all(v)));
    sort(v.begin()+1, v.end(), [&](const p &a, const p &b){
        int cw = ccw(v[0], a, b);
        if(cw) return cw > 0;
        return dst(v[0], a) < dst(v[0], b);
    });
    vector<p> ret;
    for(auto i : v){
        while(ret.size() >= 2 && ccw(ret[ret.size()-2], ret.back(), i) <= 0) ret.pop_back();
        ret.push_back(i);
    }
    return ret;
}

int chkOn(p a, p b, p t){
    return ccw(a, b, t) == 0 && min(a, b) <= t && t <= max(a, b);
}

int chkTriangle(p a, p b, p c, p t){
    if(chkOn(a, b, t) || chkOn(b, c, t) || chkOn(c, a, t)) return 1;
    p tt = {ll(2e9), t.y+1};
    int cnt = cross(a, b, t, tt) + cross(b, c, t, tt) + cross(c, a, t, tt);
    return cnt & 1;
}

int chk(p t){
    for(int i=0; i<n; i++){
        int j = i+1; if(j == n) j = 0;
        int cw = ccw(v[i], v[j], t);
        if(cw < 0){
            return 0;
        }
        if(cw == 0){
            if(min(v[i], v[j]) <= t && t <= max(v[i], v[j])) return 1;
            return 0;
        }
    }
    int l = 0, r = n - 1;
    while(l < r){
        int m = l + r + 1 >> 1;
        if(ccw(v[0], v[m], t) >= 0) l = m;
        else r = m - 1;
    }
    return chkTriangle(v[0], v[l], v[l+1], t);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n; v.resize(n);
    for(auto &i : v) cin >> i.x >> i.y;
    v = getConvexHull(); n = v.size();

    int ans = 0; cin >> q;
    while(q--){
        p t; cin >> t.x >> t.y;
        ans += chk(t);
    }
    cout << ans;
}