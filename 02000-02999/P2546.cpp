#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
ll a[202020], b[202020], sa, sb;

void solve(){
    int n; cin >> n >> m; sa = sb = 0;
    int ans = 0;
    for(int i=1; i<=n; i++) cin >> a[i], sa += a[i];
    for(int i=1; i<=m; i++) cin >> b[i], sb += b[i];
    for(int i=1; i<=n; i++){
        if(a[i]*n < sa && a[i] * m > sb) ans++;
    }
    cout <<ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}