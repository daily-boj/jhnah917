#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n; string v[22];
int dp[22][1 << 17];

int eval(int bit){
    int ret = 0;
    for(int i=0; i<n; i++) if(bit & (1 << i)) ret += v[i].size();
    return ret;
}

int f(int idx, int bit){
    int &res = dp[idx][bit];
    if(res != -1) return res;
    if(idx == n) return res = eval(bit);
    res = eval(bit);
    for(int i=0; i<n; i++){
        if(bit & (1 << i)) continue;
        if(v[idx].back() != v[i][0]) continue;
        res = max(res, f(i, bit | (1 << i)));
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n; for(int i=0; i<n; i++) cin >> v[i];
    memset(dp, -1, sizeof dp);
    int ans = 0;
    for(int i=0; i<n; i++) ans = max(ans, f(i, 1 << i));
    cout << ans;
}