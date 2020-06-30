#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

ll pw(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1) ret= ret * a % mod;
        b >>= 1; a = a * a % mod;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n; ll ret = 0;
    for(int i=0; i<n; i++){
        ll a, b; cin >> a >> b;
        if(!b) continue;
        ret += a * b % mod * pw(2, b-1) % mod;
        ret %= mod;
    }
    cout << ret;
}