#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

void solve(){
    ll ans = 1;
    int flag = (n < 0);
    n = abs(n);
    for(ll i=2; i*i<=n; i++){
        ll now = 1;
        for(ll j=1; ; j++){
            now *= i; if(now > n) break;
            if(now == n){
                if(!flag || j % 2 == 1) ans = max(ans, j);
            }
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(1){
        cin >> n;
        if(!n) break;
        solve();
    }
}