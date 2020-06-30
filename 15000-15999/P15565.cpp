#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n, k;
int a[1010101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i], a[i] %= 2;
    int now = a[1], i = 1, j = 1, ans = 1e9+7;
    while(1){
        if(i == n && j == n) break;
        if(j == n){
            now -= a[i++];
            if(now >= k) ans = min(ans, j-i+1);
            continue;
        }
        if(i == j || now < k){
            now += a[++j];
            if(now >= k) ans = min(ans, j-i+1);
            continue;
        }
        now -= a[i++];
        if(now >= k) ans = min(ans, j-i+1);
    }
    cout << (ans > 1e9 ? -1 : ans);
}