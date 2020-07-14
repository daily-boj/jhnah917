#include <bits/stdc++.h>
using namespace std;

int n, m;
int x[10101], y[10101];

void solve(){
    for(int i=1; i<=n; i++) cin >> x[i] >> y[i] >> x[i] >> y[i];
    while(m--){
        int cnt = 0;
        int a, b; cin >> a >> b; b += a;
        for(int i=1; i<=n; i++){
            int s = x[i], e = x[i] + y[i];
            if(b <= s || e <= a) continue;
            cnt++;
        }
        cout << cnt << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(1){
        cin >> n >> m;
        if(!n && !m) break;
        solve();
    }
}