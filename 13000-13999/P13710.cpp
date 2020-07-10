#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n;
int a[101010];
int cnt[33][2];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) a[i] ^= a[i-1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<30; j++){
            int t = (a[i] & (1 << j)) != 0;
            cnt[j][t]++;
        }
    }
    ll ans = 0;
    for(int i=0; i<30; i++){
        ll t = 1LL * cnt[i][0] * cnt[i][1];
        ans += t * (1LL << i);
    }
    cout << ans;
}