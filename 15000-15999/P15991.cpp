#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
const ll mod = 1e9+9;

ll dp[101010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    dp[0] = 1;
    for(int i=1; i<101010; i++){
        for(int j=1; j<=3; j++){
            if(i-j < 0) continue;
            dp[i] = (dp[i] + dp[i-j]) % mod;
        }
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll ans = 0;
        if(n & 1) ans = (dp[(n-1)/2] + dp[(n-3)/2]) % mod;
        else ans = (dp[n/2] + dp[(n-2)/2]) % mod;
        cout << ans << "\n";
    }
}