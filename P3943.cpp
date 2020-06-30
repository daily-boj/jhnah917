#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

map<int, int> dp;

int f(int x){
    if(dp.count(x)) return dp[x];
    if(x == 1) return dp[x] = 1;
    if(x & 1) return dp[x] = max(x, f(x*3+1));
    return dp[x] = max(x, f(x/2));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << f(n) << "\n";
    }
}