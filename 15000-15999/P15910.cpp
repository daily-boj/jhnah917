#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
const int inf = 1e9+7;

int dp[101010][11];
string s; int n;

int trans[11][3] = {
        {0, 1, 0},
        {2, 1, 0},
        {0, 0, 3},
        {4, 0, 0},
        {0, 0, 5},
        {6, 0, 0},
        {0, 1, 5}
};

int cost(char i, int j){
    int t;
    if(i == 'A') t = 0;
    if(i == 'B') t = 1;
    if(i == 'N') t = 2;
    return t != j;
}

int f(int idx, int flag){
    int &res = dp[idx][flag];
    if(res != -1) return res;
    if(idx == n) return res = flag == 6 ? 0 : inf;
    res = inf;
    for(int k=0; k<3; k++) if(trans[flag][k]) res = min(res, f(idx+1, trans[flag][k]) + cost(s[idx], k));
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> s; n = s.size(); dp[0][0] = 1;
    memset(dp, -1, sizeof dp);
    cout << f(0, 0);
}