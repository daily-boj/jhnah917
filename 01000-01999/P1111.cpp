#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n, v[111];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> v[i];
    if(n == 1){ cout << "A"; return 0; }
    if(n == 2){
        if(v[1] != v[2]) cout << "A";
        else cout << v[1];
        return 0;
    }
    ll a, b;
    if(v[1] == v[2]){
        if(v[2] != v[3]){ cout << "B"; return 0; }
        a = 1, b = 0;
    }else{
        if((v[3] - v[2]) % (v[2] - v[1]) != 0){ cout << "B"; return 0; }
        a = (v[3] - v[2]) / (v[2] - v[1]);
        b = v[2] - v[1] * a;
    }
    for(int i=2; i<=n; i++) if(v[i] != a*v[i-1]+b){ cout << "B"; return 0; }
    cout << a*v[n]+b;
}