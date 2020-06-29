#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n;
int a[1010];
int le[1010], ri[1010];
vector<string> ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> le[i];
    int l = n, r = 0;
    while(l+r){
        while(l){
            if(le[l] == n){ans.push_back("1 3"); n--; l--; break; }
            ri[++r] = le[l--];
            ans.push_back("1 2");
        }
        while(r){
            if(ri[r] == n){ ans.push_back("2 3"); n--; r--; break; }
            le[++l] = ri[r--];
            ans.push_back("2 1");
        }
    }
    cout << ans.size() << "\n";
    for(auto i : ans) cout << i << "\n";
}