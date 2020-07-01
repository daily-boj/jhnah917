#include <bits/stdc++.h>
using namespace std;

int a[2020202];
int x[1010101], y[1010101];
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x[i] >> y[i];
        v.push_back(x[i]);
        v.push_back(y[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=1; i<=n; i++){
        x[i] = lower_bound(v.begin(), v.end(), x[i]) - v.begin();
        y[i] = lower_bound(v.begin(), v.end(), y[i]) - v.begin();
        a[x[i]]++; a[y[i]]--;
    }
    for(int i=1; i<2020202; i++) a[i] += a[i-1];
    cout << *max_element(a, a+2020202);
}