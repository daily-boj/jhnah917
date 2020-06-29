#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n, a, b, c;
int ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++){
        string s; cin >> s;
        if(s == "1/4") a++;
        else if(s == "1/2") b++;
        else c++;
    }
    ans += c;
    a -= c;
    if(b & 1) a -= 2, b++;
    ans += b / 2;
    if(a > 0) ans += (a + 3) / 4;
    cout << ans;
}