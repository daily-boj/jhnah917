#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n, m;
int a[2020][2020];
int chk[2020][2020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        char c; cin >> c; a[i][j] = c == 'W';
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        if(i+1 <= n && a[i][j] + a[i+1][j] == 1) chk[i][j] = chk[i+1][j] = 1;
        if(j+1 <= m && a[i][j] + a[i][j+1] == 1) chk[i][j] = chk[i][j+1] = 1;
    }
    ll cnt = 0;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cnt += !chk[i][j];
    ll ans = 1;
    for(int i=0; i<cnt; i++){
        ans = ans * 2 % (int)(1e9+7);
    }
    cout << ans;
}
