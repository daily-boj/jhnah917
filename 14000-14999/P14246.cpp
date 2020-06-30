#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n;
ll a[101010], k;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    cin >> k;

    int j = 1;
    ll now = a[1];
    ll ans = 0;
    for(int i=1; i<=n; i++){
        while(j+1 <= n && now <= k) now += a[++j];
        if(now > k) ans += n-j+1;
        now -= a[i];
    }
    cout << ans;
}