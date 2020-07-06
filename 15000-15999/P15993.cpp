#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
const ll mod = 1e9+9;

ll dp[101010][2];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    dp[0][0] = 1;
    for(int i=1; i<101010; i++){
        for(int j=1; j<=3; j++){
            if(i-j < 0) continue;
            dp[i][0] = (dp[i][0] + dp[i-j][1]) % mod;
            dp[i][1] = (dp[i][1] + dp[i-j][0]) % mod;
        }
    }
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << dp[n][1] << " " << dp[n][0] << "\n";
    }
}