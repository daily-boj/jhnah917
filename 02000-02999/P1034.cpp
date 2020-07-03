#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define int long long
using namespace std;

typedef long long ll;

int n, m, k;
int a[55][55];
ll bit[55], cnt[55];

int chk[55];

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
            char c; cin >> c; a[i][j] = c == '1'; bit[i] |= (a[i][j] << j); cnt[i] += 1 - a[i][j];
        }
    cin >> k;
    for(int i=1; i<=n; i++){
        if(cnt[i] % 2 == k % 2 && cnt[i] <= k) chk[i] = 1;
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(!chk[i]) continue;
        int now = 0;
        for(int j=1; j<=n; j++) if(bit[i] == bit[j]) now++;
        ans = max(ans, now);
    }
    cout << ans;
}