#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

int n;
p v[1010101];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> v[i].x >> v[i].y;
    sort(v+1, v+n+1, [](p a, p b){
        ll aa = a.y - a.x, bb = b.y - b.x;
        if(aa >= 0 && bb < 0) return true;
        if(aa < 0 && bb >= 0) return false;
        if(aa < 0) return a.y > b.y;
        return a.x < b.x;
    });

    ll a = 0, b = 0;
    for(int i=1; i<=n; i++){
        ll aa = min(-a, -a+b-v[i].x);
        ll bb = -a+b-v[i].x+v[i].y;
        bb -= aa; aa = -aa;
        a = aa; b = bb;
    }
    cout << a;
}