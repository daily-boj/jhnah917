#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n, m, k;
int a[111];

int cnt(int bit){
    int ret = 0;
    while(bit){ ret += (bit & 1); bit >>= 1; }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++) for(int j=1; j<=k; j++){
            int t; cin >> t; t--; a[i] |= (1 << t);
        }
    int ans = 0;
    for(int bit=0; bit<(1<<(n+n)); bit++){
        if(cnt(bit) != n) continue;
        int now = 0;
        for(int i=1; i<=m; i++){
            if((bit & a[i]) == a[i]) now++;
        }
        ans = max(ans, now);
    }
    cout << ans;
}