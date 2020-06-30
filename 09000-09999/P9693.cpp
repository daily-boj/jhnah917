#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n, pv;
int two[1010101], five[1010101];

void init(){
    for(int i=1; i<1010101; i++){
        int t = i;
        while(t % 2 == 0) two[i]++, t /= 2;
        t = i;
        while(t % 5 == 0) five[i]++, t /= 5;
        two[i] += two[i-1];
        five[i] += five[i-1];
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    init();
    while(1){
        cin >> n;
        if(!n) break;
        cout << "Case #" << ++pv << ": " << min(two[n], five[n]) << "\n";
    }
}