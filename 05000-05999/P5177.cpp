#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

string a, b, x, y;

void conv(string &a, string x){
    for(auto i : x){
        if('a' <= i && i <= 'z'){ a += i; continue; }
        if('A' <= i && i <= 'Z'){ a += char(i+32); continue; }
        if('0' <= i && i <= '9'){ a += i; continue; }
        if(i == ' '){
            if(a.empty() || a.back() == ' ') continue;
            if(!('0' <= a.back() && a.back() <= '9') && !('a' <= a.back() && a.back() <= 'z')) continue;
            a += i; continue;
        }
        while(!a.empty() && a.back() == ' ') a.pop_back();
        if(i == '(' || i == '{' || i == '[') a += '(';
        else if(i == ')' || i == '}' || i == ']') a += ')';
        else if(i == ',' || i == ';') a += ';';
        else a += i;
    }
    while(!a.empty() && a.back() == ' ') a.pop_back();
}

int pv;
void solve(){
    a = ""; b = "";
    getline(cin, x);
    getline(cin, y);
    conv(a, x);
    conv(b, y);
    cout << "Data Set " << ++pv << ": ";
    if(a == b) cout << "equal\n";
    else cout << "not equal\n";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t; getline(cin, a);
    while(t--) solve();
}