#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    if(s.size() == 1){ cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!"; return 0; }
    int d = s[1] - s[0];
    for(int i=2; i<s.size(); i++){
        if(s[i] - s[i-1] != d){ cout << "흥칫뿡!! <(￣ ﹌ ￣)>"; return 0; }
    }
    cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
}