#include <bits/stdc++.h>
using namespace std;

string s, t;

int f(string now){
    if(s.size() == now.size()) return s == now;
    if(s.size() > now.size()) return 0;
    int ret = 1;
    if(now[0] == 'A'){
        if(now.back() == 'A'){
            auto tmp = now; tmp.pop_back();
            if(f(tmp)) return 1;
        }
        return 0;
    }
    else{
        if(now.back() == 'A'){
            auto tmp = now; tmp.pop_back();
            if(f(tmp)) return 1;
        }
        reverse(now.begin(), now.end());
        auto tmp = now; tmp.pop_back();
        if(f(tmp)) return 1;
    }
    return 0;
}

int main(){
    cin >> s >> t;
    cout << f(t);
}