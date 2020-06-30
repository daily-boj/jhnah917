#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int n, m;
vector<p> v;

ll tree[1 << 12];
const int sz = 1 << 11;
void update(int x, int v){
    x |= sz; tree[x] += v;
    while(x >>= 1) tree[x] += v;
}
ll query(int l, int r){
    l |= sz; r |= sz;
    ll ret = 0;
    while(l <= r){
        if(l & 1) ret += tree[l++];
        if(~r & 1) ret += tree[r--];
        l >>= 1; r >>= 1;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m; v.resize(m);
    for(auto &i : v) cin >> i.x >> i.y;
    sort(all(v));

    ll ans = 0;
    for(auto i : v){
        ans += query(i.y+1, n+1);
        update(i.y, 1);
    }
    cout << ans;
}