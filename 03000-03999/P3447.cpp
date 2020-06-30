#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    while(!cin.eof()){
        string s; getline(cin, s);
        string ans;
        for(auto i : s){
            ans += i;
            while(ans.size() >= 3 && ans[ans.size()-3] == 'B' && ans[ans.size()-2] == 'U' && ans.back() == 'G'){
                ans.pop_back();
                ans.pop_back();
                ans.pop_back();
            }
        }
        cout << ans << "\n";
    }
}