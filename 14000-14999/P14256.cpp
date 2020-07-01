#include <bits/stdc++.h>
using namespace std;

vector<int> prime;
int chk[1010];
void era(){
    for(int i=2; i<1010; i++){
        if(chk[i]) continue;
        prime.push_back(i);
        for(int j=i+i; j<1010; j+=i) chk[j] = 1;
    }
}

vector<int> soinsu(int n){
    vector<int> ret;
    for(auto i : prime){
        if(i*i > n) break;
        while(n%i == 0) n /= i, ret.push_back(i);
    }
    if(n != 1) ret.push_back(n);
    vector<int> rem;
    for(int i=0; i<ret.size(); i++){
        if(rem.size() && rem.back() == ret[i]) rem.pop_back();
        else rem.push_back(ret[i]);
    }
    return rem;
}

int main(){
    era();
    int n, m; cin >> n >> m;
    int ans = 0;
    for(int i=1; i<=n; i++){
        auto vec = soinsu(i);
        int t = 1;
        for(auto i :vec) t *= i;
        for(int j=1; ; j++){
            if(t*j*j > m) break;
            ans++;
        }
    }
    cout << ans;
}