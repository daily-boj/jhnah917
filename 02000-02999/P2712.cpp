#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

inline double kg(double x){ return x * 2.2046; }
inline double lb(double x){ return x * 0.4536; }
inline double l(double x){ return x * 0.2642; }
inline double g(double x){ return x * 3.7854; }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        double n; string s; cin >> n >> s;
        if(s == "kg") cout << fixed << setprecision(4) << kg(n) << " " << "lb\n";
        if(s == "lb") cout << fixed << setprecision(4) << lb(n) << " " << "kg\n";
        if(s == "l") cout << fixed << setprecision(4) << l(n) << " " << "g\n";
        if(s == "g") cout << fixed << setprecision(4) << g(n) << " " << "l\n";
    }
}