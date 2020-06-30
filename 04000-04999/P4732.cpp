#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

vector<string> v; int t;

int f(string s){
    int ret = 0, flag = 0;
    if(s[0] == '-'){
        flag = 1; s.erase(s.begin());
    }
    for(auto i : s) ret = ret * 10 + (i - '0');
    if(flag) ret *= -1;
    return ret;
}

string arr[] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
map<string, int> mp;

void solve(){
    vector<int> a;
    for(auto i : v) a.push_back(mp[i] + t);
    for(auto &i : a){
        i %= 12; i += 12; i %= 12;
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    for(int i=0; i<12; i++) mp[arr[i]] = i;
    mp["Ab"] = 11;
    mp["Bb"] = 1; mp["B#"] = 3;
    mp["Cb"] = 2;
    mp["Db"] = 4;
    mp["Eb"] = 6; mp["E#"] = 8;
    mp["Fb"] = 8;
    mp["Gb"] = 9;
    while(1){
        string s; v.clear();
        while(1){
            cin >> s; if(s == "***") break;
            if('0' <= s[0] && s[0] <= '9' || s[0] == '-'){
                t = f(s); break;
            }
            v.push_back(s);
        }
        if(s == "***") break;
        solve();
    }
}