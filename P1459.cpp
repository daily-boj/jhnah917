#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll x, y, w, s; cin >> x >> y >> w >> s;
    if(x < y) swap(x, y);
    ll ans = min({w * (x + y), y * s + w * (x - y), (x - (x + y) % 2) * s + (x + y) % 2 * w});
    cout << ans;
}
