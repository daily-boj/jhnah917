#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
typedef pair<double, int> p;

struct Line{
    double a, b, i;
    Line(double a, double b, int i) : a(a), b(b), i(i) {}
    Line() : Line(0, 0, 0) {}
    double f(double x){ return a*x+b; }
};

struct CHT{
    vector<Line> v; int pv;
    void init(){
        v.clear(); pv = 0;
    }
    bool chk(const Line a, const Line b, const Line c){
        return (a.b - b.b) * (b.a - c.a) <= (c.b - b.b) * (b.a - a.a);
    }
    void insert(const Line t){
        while(v.size() >= 2 && chk(v[v.size()-2], v.back(), t)) v.pop_back();
        v.push_back(t);
    }
    p query(int x){
        while(pv+1 < v.size() && v[pv].f(x) < v[pv+1].f(x)) pv++;
        return p(v[pv].f(x), v[pv].i);
    }
} cht;

int n, k;
double dp[101010];
int cnt[101010];

int chk(double c){
    cht.init();
    for(int i=1; i<=n; i++){
        cht.insert(Line(dp[i-1], -i+1, i-1));
        p now = cht.query(i);
        cnt[i] = cnt[now.y] + 1;
        dp[i] = now.x / i + 1 - c;
    }
    return cnt[n];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k;
    double l = 0, r = 1e6;
    for(int i=0; i<111; i++){
        double m = (l + r) / 2;
        if(chk(m) <= k) r = m;
        else l = m;
    }
    chk(r);
    cout << fixed;
    cout.precision(10);
    cout << dp[n] + k * r;
}