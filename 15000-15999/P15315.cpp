#pragma GCC target ("avx,avx2,fma")
#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;
const double pi = acos(-1);

ll pw(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1) ret = ret * a % mod;
        b >>= 1; a = a * a % mod;
    }
    return ret;
}

// FFT
#include <smmintrin.h>
#include <immintrin.h>
__m256d mult(__m256d a, __m256d b){
    __m256d c = _mm256_movedup_pd(a);
    __m256d d = _mm256_shuffle_pd(a, a, 15);
    __m256d cb = _mm256_mul_pd(c, b);
    __m256d db = _mm256_mul_pd(d, b);
    __m256d e = _mm256_shuffle_pd(db, db, 5);
    __m256d r = _mm256_addsub_pd(cb, e);
    return r;
}
void hell_joseon_fft(int n, __m128d a[], bool inv = false){
    for(int i=1, j=0; i<n; ++i){
        int bit = n>>1;
        for(;j>=bit;bit>>=1) j -= bit;
        j += bit;
        if(i<j) swap(a[i], a[j]);
    }
    for(int len=2; len<=n; len<<=1){
        double ang = 2*pi/len*(inv?-1:1);
        __m256d wlen; wlen[0] = cos(ang), wlen[1] = sin(ang);
        for(int i=0; i<n; i += len){
            __m256d w; w[0] = 1; w[1] = 0;
            for(int j=0; j<len/2; ++j){
                w = _mm256_permute2f128_pd(w, w, 0);
                wlen = _mm256_insertf128_pd(wlen, a[i+j+len/2], 1);
                w = mult(w, wlen);
                __m128d vw = _mm256_extractf128_pd(w, 1);
                __m128d u = a[i+j];
                a[i+j] = _mm_add_pd(u, vw);
                a[i+j+len/2] = _mm_sub_pd(u, vw);
            }
        }
    }
    if(inv){
        __m128d inv; inv[0] = inv[1] = 1.0/n;
        for(int i=0; i<n; ++i) a[i] = _mm_mul_pd(a[i], inv);
    }
}
vector<ll> multiply(vector<ll>& v, vector<ll>& w){
    int n = 2; while(n < v.size()+w.size()) n<<=1;
    __m128d* fv = new __m128d[n];
    for(int i=0; i<n; ++i) fv[i][0] = fv[i][1] = 0;
    for(int i=0; i<v.size(); ++i) fv[i][0] = v[i];
    for(int i=0; i<w.size(); ++i) fv[i][1] = w[i];
    hell_joseon_fft(n, fv); // (a+bi) is stored in FFT
    for(int i=0; i<n; i += 2){
        __m256d a;
        a = _mm256_insertf128_pd(a, fv[i], 0);
        a = _mm256_insertf128_pd(a, fv[i+1], 1);
        a = mult(a, a);
        fv[i] = _mm256_extractf128_pd(a, 0);
        fv[i+1] = _mm256_extractf128_pd(a, 1);
    }
    hell_joseon_fft(n, fv, 1);
    vector<ll> ret(n);
    for(int i=0; i<n; ++i) ret[i] = (ll)round(fv[i][1]/2);
    delete[] fv;
    return ret;
}

ll n, a, b;
vector<int> g[202020];
int sz[202020], use[202020];
ll cnt[202020];

// Centroid
int getSize(int v, int p){
    sz[v] = 1;
    for(auto i : g[v]) if(i != p && !use[i]){
            sz[v] += getSize(i, v);
        }
    return sz[v];
}
int getCent(int v, int p, int s){
    for(auto i : g[v]) if(i != p && !use[i]){
            if(sz[i] > s/2) return getCent(i, v, s);
        }
    return v;
}

vector<ll> subtree, acc; int depth;

void update_sub(int v, int p, int d){
    depth = max(depth, d);
    subtree[d]++;
    for(auto i : g[v]) if(i != p && !use[i]) update_sub(i, v, d+1);
}

void calc(){
    auto t = multiply(subtree, acc);
    for(int i=1; i<t.size(); i++) cnt[i] += t[i];
}

void solve(int v){
    int cent = getCent(v, -1, getSize(v, -1));
    getSize(cent, -1);
    use[cent] = 1;
    acc.resize(1); acc.reserve(sz[cent]+1);
    acc[0] = 1;
    sort(all(g[cent]), [&](int a, int b){ return sz[a] < sz[b]; });

    for(auto i : g[cent]) if(!use[i]){
            depth = 0; subtree.clear(); subtree.resize(sz[i]+1);
            update_sub(i, cent, 1);
            calc();
            if(acc.size() <= depth) acc.resize(depth+1);
            for(int j=0; j<=depth; j++) acc[j] += subtree[j];
        }
    for(auto i : g[cent]) if(!use[i]) solve(i);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> a >> b; a = b - a;
    for(int i=1; i<n; i++){
        int s, e; cin >> s >> e;
        g[s].push_back(e);
        g[e].push_back(s);
    }
    solve(1);

    ll ans = 0;
    for(int i=1; i<=n; i++){
        ll t = 1LL * i * cnt[i] % mod;
        ll aa = pw(a, i+1);
        ll tt = pw(b, n-i);
        aa = aa * tt % mod;
        t = t * aa % mod;
        ans = (ans + t) % mod;
    }
    ans = ans * pw(pw(b, n+1), mod-2) % mod;
    cout << ans;
}