#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//O(N log N)
void fft(vector<cpx> &a, bool inv){
    int n = a.size(), j = 0;
    vector<cpx> roots(n/2);
    for(int i=1; i<n; i++){
        int bit = (n >> 1);
        while(j >= bit){
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if(i < j) swap(a[i], a[j]);
    }
    for(int i=0; i<n/2; i++){
        roots[i] = 1;
    }
    for(int i=2; i<=n; i<<=1){
        int step = n / i;
        for(int j=0; j<n; j+=i){
            for(int k=0; k<i/2; k++){
                cpx u = a[j+k], v = a[j+k+i/2] * roots[step * k];
                a[j+k] = u+v;
                a[j+k+i/2] = u-v;
            }
        }
    }
    if(inv) for(int i=0; i<n; i++) a[i] /= n; // skip for OR convolution.
}

vector<ll> multiply(vector<ll> &v, vector<ll> &w) {
    vector<cpx> fv(v.begin(), v.end()), fw(w.begin(), w.end());
    int n = 2;
    while (n < v.size() + w.size()) n <<= 1;
    fv.resize(n);
    fw.resize(n);
    fft(fv, 0);
    fft(fw, 0);
    for (int i = 0; i < n; i++) fv[i] *= fw[i];
    fft(fv, 1);
    vector<ll> ret(n);
    for (int i = 0; i < n; i++) ret[i] = (ll) round(fv[i].real());
    return ret;
}

int n, k;
int arr[101010];
vector<ll> v;

int32_t main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k; v.resize(303030);
    for(int i=1; i<=n; i++){
        cin >> arr[i]; arr[i] ^= arr[i-1];
        v[arr[i]]++;
    }
    vector<int> u = v;
    v = multiply(u, v);
    v[0] -= n;
    for(int i=0; i<v.size(); i++) v[i] /= 2;
    for(int i=1; i<=n; i++) v[arr[i]]++;
    ll sum = 0;
    for(int i=0; i<v.size(); i++) if(i < k) sum += v[i];
    cout << sum;
}