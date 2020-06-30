#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
const int mod = 1000;

int n, a, b, d;
int dp[1010101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> a >> b >> d >> n; dp[0] = 1;
    for(int i=1; i<=n; i++){
        dp[i] = dp[i-1];
        if(i >= a) dp[i] += dp[i-a];
        if(i >= b) dp[i] -= dp[i-b];
        dp[i] %= mod; dp[i] += mod; dp[i] %= mod;
    }
    if(n-d >= 0) dp[n] -= dp[n-d];
    dp[n] %= mod; dp[n] += mod; dp[n] %= mod;
    cout << dp[n];
}