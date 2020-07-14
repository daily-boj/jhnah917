#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n;
string a[1010], b[1010];
map<string, int> mp;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i], mp[a[i]] = i;
    for(int i=1; i<=n; i++) cin >> b[i];
    int ans = 0;
    for(int i=1; i<=n; i++){
        int flag = 0;
        for(int j=i+1; j<=n; j++) if(mp[b[i]] > mp[b[j]]){ flag = 1; break; }
        ans += flag;
    }
    cout << ans;
}