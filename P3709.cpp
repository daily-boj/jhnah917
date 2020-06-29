#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

const int di[] = {0, 1, 0, -1};
const int dj[] = {1, 0, -1, 0};

int n, m;
int a[55][55];
int chk[55][55][4];

void solve(){
    cin >> n >> m;
    memset(a, 0, sizeof a);
    for(int i=1; i<=m; i++){
        int x, y; cin >> x >> y;
        a[x][y] = 1;
    }
    int i, j, d; cin >> i >> j;
    if(j == 0) d = 0;
    else if(i == 0) d = 1;
    else if(j == n + 1) d = 2;
    else d = 3;
    memset(chk, 0, sizeof chk);
    while(1){
        if(chk[i][j][d]){ cout << "0 0\n"; return; }
        chk[i][j][d] = 1;
        if(a[i][j]) d = (d + 1) % 4;
        i += di[d]; j += dj[d];
        if(i == 0 || j == 0 || i == n+1 || j == n+1){
            cout << i << " " << j << "\n"; return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}