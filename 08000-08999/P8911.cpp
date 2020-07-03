#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};

void solve(){
    string s; cin >> s;
    int x = 0, y = 0, mnx = 0, mny = 0, mxx = 0, mxy = 0, d = 0;
    for(auto i : s){
        if(i == 'F'){ x += di[d]; y += dj[d]; }
        else if(i == 'B'){ x -= di[d]; y -= dj[d]; }
        else if(i == 'L'){ d--; if(d == -1) d = 3; }
        else if(i == 'R'){ d++; if(d == 4) d = 0; }
        mnx = min(mnx, x); mxx = max(mxx, x);
        mny = min(mny, y); mxy = max(mxy, y);
    }
    cout << (mxx-mnx)*(mxy-mny) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}