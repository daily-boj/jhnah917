#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n, k;
ll a[222][2];
ll dp[222][222][3]; //i까지, j개 막고, i번째의 상태가 k

ll f(int i, int j, int flag){
    ll &res = dp[i][j][flag];
    if(res != -1) return res;
    if(!j) return res = 0;
    if(i == n + 1) return res = 1e18;
    if(flag == 0) return res = min({f(i+1, j, 0), f(i+1, j-1, 1) + a[i][0], f(i+1, j-1, 2) + a[i][1]});
    if(flag == 1) return res = min(f(i+1, j, 0), f(i+1, j-1, 1) + a[i][0]);
    if(flag == 2) return res = min(f(i+1, j, 0), f(i+1, j-1, 2) + a[i][1]);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    while(1){
        cin >> n >> k;
        ll s = 0;
        if(!n && !k) break;
        memset(dp, -1, sizeof dp);
        for(int i=1; i<=n; i++) cin >> a[i][0] >> a[i][1], s += a[i][0] + a[i][1];
        cout << s - min({f(1, k, 0), f(1, k, 1), f(1, k, 2)}) << "\n";
    }
}