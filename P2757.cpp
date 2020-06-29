#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s;
    while(cin >> s){
        int a = 0, b = 0, flag = 0;
        if(s == "R0C0") break;
        for(auto i : s){
            if(i == 'R') continue;
            if(i == 'C'){ flag = 1; continue; }
            if(flag) b = b * 10 + (i - '0');
            else a = a * 10 + (i - '0');
        }
        string ans;
        while(b){
            b--;
            ans += char(b%26 + 'A');
            b /= 26;
        }
        reverse(all(ans));
        cout << ans << a << "\n";
    }
}