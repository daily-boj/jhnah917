#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

p tree[1 << 18];
const int sz = 1 << 17;
void update(int x, int v){
    x |= sz; tree[x].x = tree[x].y = v;
    while(x >>= 1){
        tree[x].x = tree[x << 1].x + tree[x << 1 | 1].x;
        tree[x].y = min(tree[x << 1].y, tree[x << 1].x + tree[x << 1 | 1].y);
    }
}

int n; string s;
int a[101010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    n = s.size();
    s = "#" + s;
    for (int i = 1; i <= n; i++) {
        a[i] = s[i] == '(' ? 1 : -1;
        update(i, a[i]);
    }
    int ans = 0;
    int q; cin >> q;
    while(q--){
        int t; cin >> t; a[t] *= -1;
        update(t, a[t]);
        if(tree[1].x == 0 && tree[1].y >= 0) ans++;
    }
    cout << ans;
}