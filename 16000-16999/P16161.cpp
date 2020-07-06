#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n, a[101010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n; for(int i=1; i<=n; i++) cin >> a[i];

    int l, r, mx = 0;
    for(int i=1; i<=n; i++){
        l = r = i; int prv = 1e9+7, now = 0;
        while(1 <= l && r <= n && a[l] == a[r] && a[r] < prv){
            prv = a[r]; now += 2; l--; r++;
        }
        mx = max(mx, now-1);
    }
    for(int i=1; i+1<=n; i++){
        l = r = i; r++; int prv = 1e9+7, now = 0;
        while(1 <= l && r <= n && a[l] == a[r] && a[r] < prv){
            prv = a[r]; now += 2; l--; r++;
        }
        mx = max(mx, now);
    }
    cout << mx;
}