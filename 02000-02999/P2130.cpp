#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n; ll t;
ll b[50505], h[50505], w[50505], d[50505];
// 위치, 높이, 너비, 깊이

double chk(double x){
    double ret = 0;
    for(int i=1; i<=n; i++){
        if(b[i] + h[i] <= x) ret += w[i] * d[i] * h[i];
        else if(b[i] < x) ret += w[i] * d[i] * (x - b[i]);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> b[i] >> h[i] >> w[i] >> d[i];
    cin >> t;

    ll mx = 0, sum = 0;
    for(int i=1; i<=n; i++) mx = max(mx, b[i] + h[i]), sum += h[i] * w[i] * d[i];
    if(t > sum){ cout << "OVERFLOW"; return 0; }

    double l = 0, r = mx;
    for(int i=0; i<1000; i++){
        double m = (l + r) / 2.0;
        if(chk(m) < t) l = m;
        else r = m;
    }
    cout << fixed; cout.precision(2);
    cout << r;
}