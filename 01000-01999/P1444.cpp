#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

string s; int n;

int id(char a, char b){
    if(a <= 'Z') return (a - 'A') * 26 + (b - 'a') + 1;
    return (a - 'a') * 26 + (b - 'A') + 1 + 26*26;
}

vector<int> g[2020];
int par[2020], chk[2020];

int dfs(int v){
    chk[v] = 1;
    for(auto i : g[v]){
        if(chk[i]) continue; chk[i] = 1;
        if(par[i] == -1 || dfs(par[i])){
            par[i] = v; return 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> s; n = s.size();
    int st = id(s[0], s[1]), ed = id(s[n-2], s[n-1]);
    for(int i=1; i<n-1; i++){
        int a = id(s[i-1], s[i]), b = id(s[i], s[i+1]);
        if(a == st || a == ed || b == st || b == ed) continue;
        g[a].push_back(b); g[b].push_back(a);
    }
    int ans = 0;
    memset(par, -1, sizeof par);
    for(int i=1; i<=26*26; i++){
        memset(chk, 0, sizeof chk);
        ans += dfs(i);
    }
    if(st == ed) ans++;
    else ans += 2;
    cout << ans;
}