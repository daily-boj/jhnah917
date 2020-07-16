#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

string s;

int small(){
    if(s == "1") return 1;
    if(s == "2") return 2;
    if(s == "6") return 3;
    if(s == "24") return 4;
    if(s == "120") return 5;
    if(s == "720") return 6;
    if(s == "5040") return 7;
    if(s == "40320") return 8;
    if(s == "362880") return 9;
    if(s == "3628800") return 10;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> s; int t = small();
    if(t){ cout << t; return 0; }
    double lg = log10(3628800.0);
    for(int i=11; ; i++){
        lg += log10(1.0 * i);
        if(floor(lg) + 1 == s.size()){
            cout << i; return 0;
        }
    }
}