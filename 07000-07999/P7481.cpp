#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        ll a, b, s, flag = 0; cin >> a >> b >> s;
        if(a > b) swap(a, b), flag = 1;
        ll x = 0, y = s/b;
        for(int i=0; i<10000&&y>=0; i++){
            ll t = s - y*b;
            if(t%a == 0){ x = t/a; break; }
            y--;
        }
        if(x >= 0 && y >= 0 && a*x + b*y == s){
            if(flag) swap(x, y);
            cout << x << " " << y << "\n";
        }else{
            cout << "Impossible\n";
        }
    }
}