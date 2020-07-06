#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
const ll mod = 1e9+9;

ll dp[1010][1010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    dp[0][0] = 1;
    for(int i=1; i<1010; i++) for(int j=1; j<1010; j++){
            for(int k=1; k<=3; k++) if(i-k >= 0){
                    dp[i][j] = (dp[i][j] + dp[i-k][j-1]) % mod;
                }
        }
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        cout << dp[a][b] << "\n";
    }
}