#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n, x;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n; v.resize(n);
    for(auto &i : v) cin >> i;
    cin >> x;
    sort(all(v));
    ll ans = 0;
    for(int i=0; i<n-1; i++){
        auto t = equal_range(v.begin()+i+1, v.end(), x-v[i]);
        ans += distance(t.x, t.y);
    }
    cout << ans;
}