#include <bits/stdc++.h>
using namespace std;

int a[33] = {0, 1, 0};
int b[33] = {0, 0, 1};

int main(){
    int d, k; cin >> d >> k;
    for(int i=3; i<=d; i++){
        a[i] = a[i-1] + a[i-2];
        b[i] = b[i-1] + b[i-2];
    }

    for(int i=0; i<=k; i++){
        int now = k - i * a[d];
        if(now % b[d] == 0){
            cout << i << "\n" << now/b[d];
            return 0;
        }
    }
}