#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

int chk[1010101];
vector<int> prime;

void era(){
    for(int i=2; i<1010101; i++){
        if(chk[i]) continue;
        prime.push_back(i);
        for(int j=i+i; j<1010101; j+=i) chk[j] = 1;
    }
}

vector<p> soinsu(ll n){
    vector<p> ret;
    for(__int128_t i : prime){
        if(i*i > n) break;
        if(n % i) continue;
        int cnt = 0;
        while(n % i == 0) n /= i, cnt++;
        ret.emplace_back(i, cnt);
    }
    if(n != 1) ret.emplace_back(n, 1);
    return ret;
}

ll f(ll n, ll x, ll y){
    ll lim = log(n) / log(x);
    ll ret = 0, t = x;
    for(ll i=0; i<lim; i++){
        ret += n / t; t *= x;
    }
    return ret / y;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    era();
    while(t--){
        ll n, k; cin >> n >> k;
        auto v = soinsu(k); ll ans = 1e18;
        for(auto i : v){
            ans = min(ans, f(n, i.x, i.y));
        }
        cout << ans << "\n";
    }
}