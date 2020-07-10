#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t lll;

ll m, n;
ll a[101010];

ll chk(ll x){
    ll ret = 0;
    for(int i=1; i<=n; i++){
        ret += max(0ll, a[i] - x);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> m >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    ll l = 0, r = 2e9 + 10;
    while(l < r){
        ll t = l + r >> 1;
        if(chk(t) <= m) r = t;
        else l = t + 1;
    }
    for(int i=1; i<=n; i++){
        m -= max(0ll, a[i] - r);
        a[i] -= max(0ll, a[i] - r);
    }
    priority_queue<ll> pq;
    for(int i=1; i<=n; i++) pq.push(a[i]);
    while(1){
        if(!m) break;
        if(pq.empty()) break;
        ll t = pq.top(); pq.pop();
        if(t-1 > 0) pq.push(t-1);
        m--;
    }
    ull ans = 0;
    while(pq.size()){
        ull t = pq.top(); pq.pop();
        ans += t * t;
    }
    cout << ans;
}