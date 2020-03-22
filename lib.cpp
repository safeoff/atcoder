#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(int)n; i++)
#define REPR(i, n) for(int i=(int)n-1; i>=0; i--)
#define FOR(i, m, n) for(int i=(int)m; i<(int)n; i++)
#define FORR(i, m, n) for(int i=(int)m-1; i>=(int)n; i--)
#define ALL(x) (x).begin(), (x).end()
#define ASC(v) sort(ALL(v));
#define DESC(v) sort(ALL(v), greater<int>());
#define UNIQ(a) sort(ALL(a));(a).resize(unique(ALL(a)) - a.begin());
#define PRINTD(x, d) cout << fixed << setprecision(d) << x << "\n";
#define DEBUG(x) cout<<#x<<": "<<x<<"\n"
typedef long long ll;
const double PI = acos(-1);
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
bool isprime(int x){ int i; if(x<2)return 0; else if(x==2) return 1; if(x%2==0) return 0; for(i=3; i*i<=x; i+=2) if(x%i==0) return 0; return 1; }
int digsum(int n) { int r=0; while(n>0) { r+=n%10; n/=10; } return r; }

// 順列を全探索で何かする
void sub (ll N) {
	vector<ll> R(N);
	REP(i, N) R[i] = i;
	ll i = 0;
	do {
		// 何か
		i++;
	} while (next_permutation(ALL(R)));
}
