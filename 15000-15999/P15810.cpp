#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n, m;
ll a[1010101];

int chk(ll x){
    ll sum = 0;
    for(int i=1; i<=n; i++){
        sum += x / a[i];
    }
    return sum >= m;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m; for(int i=1; i<=n; i++) cin >> a[i];

    ll l = 0, r = 1e13;
    while(l < r){
        ll m = l + r >> 1;
        if(chk(m)) r = m;
        else l = m + 1;
    }
    cout << r;
}