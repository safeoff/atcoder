#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i=0; i<(ll)n; i++)
#define REPR(i, n) for(ll i=(ll)n-1; i>=0; i--)
#define FOR(i, m, n) for(ll i=(ll)m; i<(ll)n; i++)
#define FORR(i, m, n) for(ll i=(ll)m-1; i>=(ll)n; i--)
#define ALL(x) (x).begin(), (x).end()
#define ASC(v) sort(ALL(v));
#define DESC(v) sort(ALL(v), greater<int>());
#define UNIQ(a) sort(ALL(a));(a).resize(unique(ALL(a)) - a.begin());
#define PRINTD(x, d) cout << fixed << setprecision(d) << x << "\n";
#define DEBUG(x) cout<<#x<<": "<<x<<"\n"
const double PI = acos(-1);
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
bool isprime(int x){ int i; if(x<2)return 0; else if(x==2) return 1; if(x%2==0) return 0; for(i=3; i*i<=x; i+=2) if(x%i==0) return 0; return 1; }
int digsum(int n) { int r=0; while(n>0) { r+=n%10; n/=10; } return r; }
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }

// 素因数分解
map<ll, ll> prime_factor(ll n) {
    map<ll, ll> ret;
    for(ll i=2; i*i<=n; i++) {
        while(n%i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1) ret[n] = 1;
    return ret;
}


// 無効グラフのBFS
void BFS() {
    ll N, M;
    N = 10; M = 20;
    vector<vector<ll>> G(N);
    REP(i, M) {
        ll a, b;
        a = 0; b = 3; // 無効グラフの入力
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> D(N, -1);
    queue<ll> Q;
    D[0] = 0;
    Q.push(0);
    while(!Q.empty()) {
        ll v = Q.front();
        Q.pop();
        for (ll nv : G[v]) {
            if (D[nv] != -1) continue;
            D[nv] = D[v]+1;
            Q.push(nv);
        }
    }
    // Dにたまる
    REP(i, N) {
        cout << i << ": " << D[i] << "\n";
    }
}

// bit全探索
void bit_search() {
    ll N = 19;
    for (ll bit=0; bit<(1<<N); bit++) {
        vector<ll> S;
        REP(i, N) if (bit&(1<<i)) S.push_back(i);
        REP(i, S.size()) {
            // 何か処理
            cout << S[i] << " ";
        }
        cout << "\n";
    }
}

// 順列 nPn
void nPn() {
    vector<ll> V;
    REP(i, 4) V.push_back(i);
    do {
        REP(i, V.size()) {
            cout << V[i] << " ";
        }
        cout << "\n";
    } while(next_permutation(ALL(V)));
}

// 順列 nPr
void nPr() {
    ll n = 4, r = 3;
    vector<ll> V;
    REP(i, n) V.push_back(i);
    vector<bool> B;
    REP(i, n) B.push_back(true);
    FOR(i, r, n) B[i] =false;
    map<vector<ll>, bool> M;
    do {
        vector<ll> K;
        REP(i, V.size()) {
            if (B[i]) {
                K.push_back(V[i]);
            }
        }
        if (M.count(K)!=0) continue;
        M[K] = true;
        REP(i, K.size()) {
            cout << K[i] << " ";
        }
        cout << "\n";
    } while(next_permutation(ALL(V)));
}

// 組み合わせ nCr
ll next_combination(ll sub) {
    ll x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}
void nCr() {
    ll n = 4, r = 3;
    ll bit = (1<<r)-1;
    for (; bit < (1<<n); bit = next_combination(bit)) {
        vector<ll> V;
        REP(i, n) {
            if (bit & (1<<i)) {
                V.push_back(i);
            }
        }
        REP(i, V.size()) {
            cout << V[i] << " ";
        }
        cout << "\n";
    }
}

int main(){
    BFS();
}
