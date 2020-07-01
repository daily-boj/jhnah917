#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int op; string s; cin >> op >> s;
    int n = s.size();
    if(op == 1){
        cout << s << "\n";
        for(int i=0; i<n; i++){
            if(i && 'A' <= s[i] && s[i] <= 'Z') cout << "_" << char(s[i]+32);
            else cout << s[i];
        }
        cout << "\n";
        s[0] -= 32; cout << s;
        return 0;
    }
    if(op == 2){
        for(int i=0; i<n; i++){
            if(s[i] == '_') continue;
            if(i && s[i-1] == '_') cout << char(s[i] - 32);
            else cout << s[i];
        }
        cout << "\n";
        cout << s << "\n";
        s[0] -= 32;
        for(int i=0; i<n; i++){
            if(s[i] == '_') continue;
            if(i && s[i-1] == '_') cout << char(s[i] - 32);
            else cout << s[i];
        }
        return 0;
    }
    cout << char(s[0]+32); for(int i=1; i<n; i++) cout << s[i]; cout << "\n";
    cout << char(s[0]+32);
    for(int i=1; i<n; i++){
        if(i && 'A' <= s[i] && s[i] <= 'Z') cout << "_" << char(s[i]+32);
        else cout << s[i];
    }
    cout << "\n";
    cout << s << "\n";
}