#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s; int ans = 0;
    int t = 0;
    for(int i=0; i<s.size(); i++,t++){
        if(s[i] >= 'a') continue;
        if(t % 4 == 0) continue;
        ans += 4 - t % 4;
        t += 4 - t % 4;
    }
    cout << ans;
}