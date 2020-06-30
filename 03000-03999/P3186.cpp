#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int a[10101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int k, l, n; cin >> k >> l >> n;
    for(int i=1; i<=n; i++){
        char c; cin >> c;
        a[i] = c == '1';
    }
    vector<int> v;
    int on = 1e9+7, use = 0, emp = 0;
    for(int i=1; i<=n; i++){
        if(a[i]) use++, emp = 0;
        else{
            use = 0;
            if(on < 1e9) emp++;
        }
        if(use == k) on = i;
        if(emp == l) on = 1e9+7, v.push_back(i), emp = 0;
    }
    if(on < 1e9){
        for(int i=n+1; on < 1e9; i++){
            emp++;
            if(emp == l) on = 1e9+7, v.push_back(i);
        }
    }
    if(v.empty()) cout << "NIKAD";
    else for(auto i : v) cout << i << "\n";
}
