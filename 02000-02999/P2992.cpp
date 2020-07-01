#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    string ans, ori = s;
    for(auto i : s) ans += "9";
    string nine;
    for(auto i : s) nine += "9";
    sort(s.begin(), s.end());
    do{
        if(s <= ori) continue;
        ans = min(ans, s);
    }while(next_permutation(s.begin(), s.end()));
    if(ans == nine) cout << 0;
    else cout << ans;
}