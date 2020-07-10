#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int n;
map<string, int> mp;
int a[101010];

int tree[1 << 18];
const int sz = 1 << 17;
void update(int x){
    x |= sz; tree[x]++;
    while(x >>= 1) tree[x]++;
}
int query(int l, int r){
    if(l > r) return 0;
    l |= sz; r |= sz;
    int ret = 0;
    while(l <= r){
        if(l & 1) ret += tree[l++];
        if(~r & 1) ret += tree[r--];
        l >>= 1; r >>= 1;
    }
    return ret;
}

void solve(){
    mp.clear();
    for(int i=1; i<=n; i++){
        string s; cin >> s; mp[s] = i;
    }
    for(int i=1; i<=n; i++){
        string s; cin >> s; a[i] = mp[s];
    }
    memset(tree, 0, sizeof tree);
    ll ans = 0;
    for(int i=1; i<=n; i++){
        ans += query(a[i]+1, n);
        update(a[i]);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    while(1){
        cin >> n;
        if(!n) break;
        solve();
    }
}