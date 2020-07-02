#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

ll n, m, l;
ll _a[131313], arr[131313], brr[131313];

typedef vector<ll> poly;

ll pw(ll a, ll b, ll mod){
    ll ret = 1;
    while(b){
        if(b & 1) ret = ret * a % mod;
        b >>= 1; a = a * a % mod;
    }
    return ret;
}

template<ll mod, ll w>
class NTT{
public:
    void ntt(poly &f, bool inv = 0){
        int n = f.size(), j = 0;
        vector<ll> root(n >> 1);
        for(int i=1; i<n; i++){
            int bit = (n >> 1);
            while(j >= bit){
                j -= bit; bit >>= 1;
            }
            j += bit;
            if(i < j) swap(f[i], f[j]);
        }
        ll ang = pw(w, (mod - 1) / n, mod); if(inv) ang = pw(ang, mod - 2, mod);
        root[0] = 1; for(int i=1; i<(n >> 1); i++) root[i] = root[i-1] * ang % mod;
        for(int i=2; i<=n; i<<=1){
            int step = n / i;
            for(int j=0; j<n; j+=i){
                for(int k=0; k<(i >> 1); k++){
                    ll u = f[j | k], v = f[j | k | i >> 1] * root[step * k] % mod;
                    f[j | k] = (u + v) % mod;
                    f[j | k | i >> 1] = (u - v) % mod;
                    if(f[j | k | i >> 1] < 0) f[j | k | i >> 1] += mod;
                }
            }
        }
        ll t = pw(n, mod - 2, mod);
        if(inv) for(int i=0; i<n; i++) f[i] = f[i] * t % mod;
    }
    vector<ll> multiply(poly &_a, poly &_b){
        vector<ll> a(all(_a)), b(all(_b));
        int n = 2;
        while(n < a.size() + b.size()) n <<= 1;
        a.resize(n); b.resize(n);
        ntt(a); ntt(b);
        for(int i=0; i<n; i++) a[i] = a[i] * b[i] % mod;
        ntt(a, 1);
        return a;
    }
};

ll ext_gcd(ll a, ll b, ll &x, ll &y) { //ax + by = gcd(a, b)
    ll g = a; x = 1, y = 0;
    if (b) g = ext_gcd(b, a % b, y, x), y -= a / b * x;
    return g;
}
inline ll Mod(ll a, ll b){
    a %= b; if(a < 0) a += b;
    return a;
}
ll inv(ll a, ll m){ //return x when ax mod m = 1, fail -> -1
    ll x, y;
    ll g = ext_gcd(a, m, x, y);
    if(g > 1) return -1;
    return Mod(x, m);
}

const ll m1 = 2281701377, m2 = 2483027969;
NTT<m1, 3> ntt1;
NTT<m2, 3> ntt2;

ll f(const vector<ll> a, ll mod){
    vector<ll> rmn(2), lm(2, 1);
    ll ans = 0, M = 1;
    vector<ll> m({m1, m2});
    for(int i=0; i<2; i++){
        ll k = a[i] - rmn[i]; k %= m[i];
        if(k < 0) k += m[i];
        ll x, y;
        ext_gcd(lm[i], m[i], x, y);
        k *= x; k %= m[i];
        if(k < 0) k += m[i];
        ans += k * M % (ll)5e18;
        ans %= (ll)5e18;
        for(int t=i+1; t<2; t++){
            rmn[t] += lm[t] * k;
            rmn[t] %= m[t];
            lm[t] *= m[i];
            lm[t] %= m[t];
        }
        M *= m[i]; M %= mod;
    }
    return ans;
}

poly mul(poly &a, poly &b){
    poly a1(a), a2(a);
    poly b1(b), b2(b);
    poly res1 = ntt1.multiply(a1, b1);
    poly res2 = ntt2.multiply(a2, b2);
    poly ret(res1.size());
    for(int i=0; i<res1.size(); i++){
        ret[i] = f({res1[i], res2[i]}, 1e18+7);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> l;
    for(int i=0; i<n; i++) cin >> _a[i];
    for(int i=0; i<m; i++) cin >> brr[i];
    for(ll i=0; i<n; i++){
        arr[i*m%l] += _a[i];
    }
    poly a(l), b(m);
    for(int i=0; i<l; i++) a[i] = arr[i];
    for(int j=0; j<m; j++) b[j] = brr[j];
    poly res = mul(a, b);
    vector<ll> ans(l);
    for(int i=0; i<res.size(); i++) ans[i%l] += res[i];
    for(auto i : ans) cout << i << "\n";
}