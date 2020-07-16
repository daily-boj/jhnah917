#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
ll st[1010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n;
    for(int i=1; i<=n; i++){
        int t; cin >> t;
        while(t--){ int x; cin >> x; st[i] |= (1LL << x); }
    }
    cin >> m;
    for(int i=1; i<=m; i++){
        int t; cin >> t; ll now = 0, ans = 0;
        while(t--){ int x; cin >> x; now |= (1LL << x); }
        now = ~now;
        for(int j=1; j<=n; j++) if(!(st[j] & now)) ans++;
        cout << ans << "\n";
    }
}