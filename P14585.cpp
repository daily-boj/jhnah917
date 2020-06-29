#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

ll a[333][333];
ll dp[333][333];

int n, m;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        ::a[a][b] = max(0, m - (a+b));
    }
    n = 300;
    for(int i=0; i<=n; i++) for(int j=0; j<=n; j++){
        dp[i][j] = a[i][j];
        if(i-1 >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j] + a[i][j]);
        if(j-1 >= 0) dp[i][j] = max(dp[i][j], dp[i][j-1] + a[i][j]);
    }
    cout << dp[n][n];
}