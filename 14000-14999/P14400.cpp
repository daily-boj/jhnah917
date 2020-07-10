#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n;
ll x[101010], y[101010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> x[i] >> y[i];
    sort(x+1, x+n+1);
    sort(y+1, y+n+1);
    ll a = x[n+1>>1], b = y[n+1>>1];
    ll ans = 0;
    for(int i=1; i<=n; i++) ans += abs(a-x[i]) + abs(b-y[i]);
    cout << ans;
}