#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int e, em, m, mh, h; cin >> e >> em >> m >> mh >> h;
    int ans = 0;
    while(1){
        int a = 0, b = 0, c = 0;
        if(e > 0) a++, e--;
        if(m > 0) b++, m--;
        if(h > 0) c++, h--;
        if(!a){
            if(em > 0) a++, em--;
        }
        if(!c){
            if(mh > 0) c++, mh--;
        }
        if(!b){
            if(em >= mh && em > 0) b++, em--;
            else if(em < mh && mh > 0) b++, mh--;
        }
        if(a && b && c) ans++;
        else break;
    }
    cout << ans;
}