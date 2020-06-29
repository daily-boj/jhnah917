#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n, k;
ll a[1010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i], a[i] += a[i-1];
    ll mx = -1e9;
    for(int i=k; i<=n; i++) mx = max(mx, a[i] - a[i-k]);
    cout << mx;
}