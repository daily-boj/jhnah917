#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int f(string s){
    int ret = 0;
    for(auto i : s) ret = ret * 10 + (i - '0');
    return ret;
}
string f(int n){
    return to_string(n);
}

void solve(){
    int n; cin >> n; string s = f(n);
    while(s.size() < 4) s = "0" + s;
    int cnt = 0, mn, mx;
    while(n != 6174){
        cnt++;
        sort(all(s)); mn = f(s);
        sort(all(s), greater<>()); mx = f(s);
        n = mx - mn; s = f(n);
        while(s.size() < 4) s = "0" + s;
    }
    cout << cnt << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}