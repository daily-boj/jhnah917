#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    double a, b, c; int i, j, k; cin >> a >> b >> c >> i >> j >> k;
    int g = __gcd(__gcd(i, j), k);
    i /= g; j /= g; k /= g;
    double t = min({a / i, b / j, c / k});
    cout << fixed;
    cout.precision(10);
    cout << abs(a-t*i) << " " << abs(b-t*j) << " " << abs(c-t*k);
}