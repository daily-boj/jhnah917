#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> p;

int n;
int chk[1010][1010];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    memset(chk, -1, sizeof chk);
    queue<p> q; q.emplace(1, 0); chk[1][0] = 0;
    while(q.size()){
        int a = q.front().x, b = q.front().y; q.pop();
        if(a == n){ cout << chk[a][b]; return 0; }
        if(a-1 >= 0 && chk[a-1][b] == -1){
            chk[a-1][b] = chk[a][b] + 1; q.emplace(a-1, b);
        }
        if(chk[a][a] == -1){
            chk[a][a] = chk[a][b] + 1; q.emplace(a, a);
        }
        if(a+b <= n && chk[a+b][b] == -1){
            chk[a+b][b] = chk[a][b] + 1; q.emplace(a+b, b);
        }
    }
}