#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

int chk[10101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    for(int i=0; i<q; i++){
        int a, b; cin >> a >> b;
        for(int j=a; j<=n; j+=b) chk[j] = 1;
    }
    int ans = 0;
    for(int i=1; i<=n; i++) ans += !chk[i];
    cout << ans;
}