#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
const ll mod = 998244353;

ll fac[1010101] = {1};
ll l[303030], r[303030];

ll pw(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1) ret = ret * a % mod;
        b >>= 1; a = a * a % mod;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    for(int i=1; i<1010101; i++) fac[i] = fac[i-1] * i % mod;
    l[0] = r[0] = 0;
    for(int i=1; i<303030; i++){
        l[i] = min({-l[i-1], -l[i-1]-1, -r[i-1], -r[i-1]-1});
        r[i] = max({-l[i-1], -l[i-1]-1, -r[i-1], -r[i-1]-1});
    }
    int n, m; cin >> n >> m;
    if(m < l[n] || r[n] < m){ cout << 0; return 0; }
    m -= l[n];
    cout << fac[n] * pw(fac[m], mod-2) % mod * pw(fac[n-m], mod-2) % mod;
}