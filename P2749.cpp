#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
const int mod = 1000000;
const int p = mod / 10 * 15;

int dp[p] = {0, 1};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll n; cin >> n;
    for(int i=2; i<p; i++) dp[i] = (dp[i-1] + dp[i-2]) % mod;
    cout << dp[n%p];
}