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
    return ab < 0 && cd < 0;
}

p a, b, c, d;
istream& operator >> (istream &in, p &t){
    in >> t.x >> t.y; return in;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> a >> b >> c >> d;
    if(a == b || a == c || a == d || b == c || b == d || c == d){ cout << 0; return 0; }
    cout << cross(a, b, c, d);
}