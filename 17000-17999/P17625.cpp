#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
using namespace std;

typedef long long ll;

struct p{
    ll x, y, i;
    p() : p(0, 0, 0) {}
    p(ll x, ll y) : p(x, y, 0) {}
    p(ll x, ll y, ll i) : x(x), y(y), i(i) {}
    bool operator < (const p &t) const { return tie(x, y, i) < tie(t.x, t.y, t.i); }
    bool operator == (const p &t) const { return tie(x, y, i) == tie(t.x, t.y, t.i); }
    p operator - (const p &t) const { return p(x-t.x, y-t.y); }
} v[2020];

struct Line{
    int i, j, flag; ll dx, dy;
    Line(int i, int j, int flag) : i(i), j(j), flag(flag) {
        if(flag) dx = v[i].x - v[j].x, dy = v[i].y - v[j].y;
        else dx = v[i].y - v[j].y, dy = v[j].x - v[i].x; // 수직
        if(!flag && dx < 0) dx = -dx, dy = -dy;
    }
    bool operator < (const Line &t) const {
        ll res = dx*t.dy - dy*t.dx;
        if(res) return res > 0;
        if(flag != t.flag) return flag > t.flag;
        return tie(i, j) < tie(t.i, t.j);
    }
};

inline ll ccw(const p &a, const p &b, const p &c){
    ll dx1 = b.x - a.x, dy1 = b.y - a.y;
    ll dx2 = c.x - b.x, dy2 = c.y - b.y;
    return dx1*dy2 - dx2*dy1;
}
inline ll ccw(const p &a, const p &b){ return ccw({0, 0}, a, b); }
inline double hypot(const p t){ return sqrt(t.x*t.x + t.y*t.y); }
inline double solve_triangle(p a, p b, p c){ return abs(ccw(a, b, c)) / 2.0 / (double)hypot(a-b); }

int n;
int idx[2020];
vector<Line> line;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n; for(int i=1; i<=n; i++) cin >> v[i].x >> v[i].y;
    sort(v+1, v+n+1); line.reserve(n*(n-1)/2);
    for(int i=1; i<=n; i++) v[i].i = idx[i] = i;
    for(int i=1; i<=n; i++) for(int j=1; j<i; j++) line.emplace_back(i, j, 1), line.emplace_back(i, j, 0);
    sort(all(line));

    double ans = 0;
    for(auto i : line){
        if(i.flag){
            int a = i.i, b = i.j;
            swap(v[idx[a]], v[idx[b]]); swap(idx[a], idx[b]);
            a = idx[a]; b = idx[b]; if(a > b) swap(a, b);
            if(a-1 >= 1) ans = max(ans, solve_triangle(v[a], v[b], v[a-1]));
            if(b+1 <= n) ans = max(ans, solve_triangle(v[a], v[b], v[b+1]));
            continue;
        }
        int a = idx[i.i], b = idx[i.j]; if(a > b) swap(a, b);
        int l = a, r = b;
        while(l < r){
            int m = l + r >> 1;
            if(ccw({i.dx, i.dy}, v[m]) != ccw({i.dx, i.dy}, v[a])) r = m;
            else l = m + 1;
        }
        if(!ccw({i.dx, i.dy}, v[b]-v[r])) ans = max(ans, hypot(v[a]-v[b]) / 2.0);
    }
    cout << fixed;
    cout.precision(10);
    cout << ans;
}