#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

string a, b; int n, m;
int dp[3030][3030];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> a >> b; n = a.size(), m = b.size();
    for(int i=3; i<=n; i+=3) for(int j=3; j<=m; j+=3){
            if(a.substr(i-3, 3) == b.substr(j-3, 3)) dp[i][j] = dp[i-3][j-3] + 1;
            else dp[i][j] = max(dp[i-3][j], dp[i][j-3]);
        }
    cout << dp[n][m];
}