#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

map<char, int> mp;

void solve(){
    string s; cin >> s;
    ll res = 0, tmp = 0;
    char now = 'A';
    for(auto i : s){
        if(now == i){ tmp += mp[i]; continue; }
        if(mp[now] < mp[i]){ res -= tmp; tmp = mp[i]; now = i; continue; }
        if(mp[now] > mp[i]){ res += tmp; tmp = mp[i]; now = i; continue; }
    }
    res += tmp;
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    mp['A'] = 0;
    mp['I'] = 1; mp['V'] = 5;
    mp['X'] = 10; mp['L'] = 50;
    mp['C'] = 100; mp['D'] = 500;
    mp['M'] = 1000;
    while(t--) solve();
}