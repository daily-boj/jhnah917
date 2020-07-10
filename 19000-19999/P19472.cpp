#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node{
    ll mx, mn, sum;
}tree[1 << 18];

int n, q;
ll tmp1[1 << 18];
ll tmp2[1 << 18];

Node merge(Node a, Node b){
    return {max(a.mx, b.mx), min(a.mn, b.mn), a.sum + b.sum};
}

void push(int node, int s, int e){
    if(!tmp1[node] && !tmp2[node]) return;
    if(!tmp2[node]){
        tree[node].mx += tmp1[node];
        tree[node].mn += tmp1[node];
        tree[node].sum += (e-s+1)*tmp1[node];
        if(s ^ e){
            tmp1[node*2] += tmp1[node];
            tmp1[node*2+1] += tmp1[node];
        }
    }else{
        tree[node].mx = tree[node].mn = tmp1[node] + tmp2[node];
        tree[node].sum = (e-s+1) * (tmp1[node] + tmp2[node]);
        if(s ^ e){
            tmp1[node*2] = tmp1[node];
            tmp1[node*2+1] = tmp1[node];
            tmp2[node*2] = tmp2[node];
            tmp2[node*2+1] = tmp2[node];
        }
    }
    tmp1[node] = tmp2[node] = 0;
}

ll query(int node, int s, int e, int l, int r){
    push(node, s, e);
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return tree[node].sum;
    int m = s + e >> 1;
    return query(node*2, s, m, l, r) + query(node*2+1, m+1, e, l, r);
}

void add(int node, int s, int e, int l, int r, ll v){
    push(node, s, e);
    if(r < s || e < l) return;
    if(l <= s && e <= r){
        tmp1[node] = v;
        push(node, s, e);
        return;
    }
    int m = s + e >> 1;
    add(node*2, s, m, l, r, v);
    add(node*2+1, m+1, e, l, r, v);
    tree[node] = merge(tree[node*2], tree[node*2+1]);
}

void sq(int node, int s, int e, int l, int r){
    push(node, s, e);
    if(r < s || e < l) return;
    if(l <= s && e <= r){
        if(floor(sqrt(tree[node].mn)) == floor(sqrt(tree[node].mx))){
            tmp2[node] = floor(sqrt(tree[node].mx));
            push(node, s, e);
            return;
        }
        if(tree[node].mn + 1 == tree[node].mx){
            tmp1[node] = floor(sqrt(tree[node].mn)) - tree[node].mn;
            push(node, s, e);
            return;
        }
    }
    int m = s + e >> 1;
    sq(node*2, s, m, l, r);
    sq(node*2+1, m+1, e, l, r);
    tree[node] = merge(tree[node*2], tree[node*2+1]);
}

int main(){
    //freopen("in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        ll t; cin >> t;
        add(1, 1, n, i, i, t);
    }

    while(q--){
        int op; cin >> op;
        if(op == 1){
            int a, b, c; cin >> a >> b >> c;
            add(1, 1, n, a, b, c);
        }else if(op == 2){
            int a, b; cin >> a >> b;
            sq(1, 1, n, a, b);
        }else{
            int a, b; cin >> a >> b;
            query(1, 1, n, a, b);
            cout << query(1, 1, n, a, b) << "\n";
        }
        //for(int i=1; i<=n; i++) cout << query(1, 1, n, i, i) << " "; cout << "\n";
    }
}