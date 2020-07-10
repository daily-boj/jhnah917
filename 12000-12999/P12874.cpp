#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

string s; int n;
ll dp[111][111];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> s; n = s.size(); s = "#" + s;
    dp[0][0] = 1;
    int pv = 0;
    for(int i=0; i<=n; i++){
        int a = 0, b = 0;
        for(int j=i+1; j<=n; j++) if(s[j] == '('){ a = j; break; }
        for(int j=i+1; j<=n; j++) if(s[j] == ')'){ b = j; break; }
        for(int j=0; j<=pv; j++){
            if(a) dp[a][j+1] = (dp[a][j+1] + dp[i][j]) % mod;
            if(b && j) dp[b][j-1] = (dp[b][j-1] + dp[i][j]) % mod;
        }
        if(a) pv = min(pv+1, a);
    }
    int ans = 0;
    for(int i=1; i<=n; i++) ans = (ans + dp[i][0]) % mod;
    cout << ans;
}