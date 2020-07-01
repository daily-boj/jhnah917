#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
const ll mod = 1e9+9;

ll dp[50505] = {0, 1, 1, 2};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for(int i=4; i<=n; i++) dp[i] = (dp[i-1] + dp[i-3]) % mod;
    cout << dp[n];
}