#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll a, b; cin >> a >> b;
    ll x = 0, y = b-a;
    for(ll i=1; ; i++){
        if(i*i > b) break;
        if(i*i > a) x++;
    }
    ll g = __gcd(x, y);
    if(!x) cout << 0;
    else cout << x/g << "/" << y/g;
}