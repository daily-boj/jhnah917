#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n, k, ans;
int a[11], chk[11];

void f(int x, int v){
    if(v < 500) return;
    if(x == n){ ans++; return; }
    for(int i=0; i<n; i++) if(!chk[i]){
        chk[i] = 1; f(x+1, v+a[i]); chk[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a[i]; a[i] -= k;
    }
    f(0, 500);
    cout << ans;
}