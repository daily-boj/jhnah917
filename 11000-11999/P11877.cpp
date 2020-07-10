#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

ll n, k, x;
int chk[1010101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> x; k = (n-2)*(n-1)/2;
    if(x > k){ cout << -1; return 0; }
    k -= x;
    for(int i=1; i<=n-2 && k; i++){
        if(k >= n-i-1) chk[i] = 1, k -= n-i-1;
    }
    cout << n << " ";
    for(int i=1; i<=n-2; i++) if(!chk[i]) cout << i << " ";
    cout << n-1 << " ";
    for(int i=n-2; i; i--) if(chk[i]) cout << i << " ";
}