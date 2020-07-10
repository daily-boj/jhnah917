#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

ll dp[44] = {1, 1};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    for(int i=2; i<44; i++) for(int j=0; j<i; j++) dp[i] += dp[j] * dp[i-j-1];
    int n; cin >> n;
    cout << dp[n];
}