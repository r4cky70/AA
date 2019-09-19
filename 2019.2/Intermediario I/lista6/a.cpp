#include <bits/stdc++.h>

#define mp(a, b) make_pair(a,b)
#define pb(a) push_back(a)
#define all(a) a.begin(), a.end()
#define debug(...) cerr<<"["<<#__VA_ARGS__<<": "<<(__VA_ARGS__)<<"]\n"
#define debugarr(a, b) for(int i=0;i<b;++i)\
cerr<<a[i]<<" "; cerr<<endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector < int > vi;
typedef vector < ll > vll;
typedef pair < int, int > pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = (int)__builtin_inf();
const int MAXS = 100007;
const ll MOD = 1000000007;
#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<ll>> matrix;

ll multi(ll a, ll b){
  return (a%MOD) * (b%MOD)%MOD;
}
ll sub(ll a, ll b){
  return (((a % MOD) - (b % MOD) % MOD) + MOD) % MOD;
}

matrix operator *(matrix a, matrix b) {
	int n = (int)a.size();
	int m = (int)b.size();
	int p = (int)b[0].size();
	matrix c(n, vector<ll>(p));
	ll col[m];
	for (int j = 0; j < p; j++) {
		for (int k = 0; k < m; k++)
			col[k] = b[k][j];
		for (int i = 0; i < n; i++) {
			ll s = 0;
			for (int k = 0; k < m; k++)
				s += multi(a[i][k], col[k]);
			c[i][j] = s;
		}
	}
	return c;
}

matrix det(ll n){
  matrix c(n, vector<ll>(n));
  for(int i = 0; i < n; ++i) c[i][i] = 1;
  return c;
}

matrix exp(matrix a, int b){
  if(b == 0) return det(a.size());
  matrix c = exp(a, b/2);
  c = c*c;
  if(b%2 != 0) c = c*a;
  return c;
}

void solve(){
  int t;
  cin >> t;
  ll n, m;
  matrix a = {{1, 1, 1},{1, 0, 1}, {0, 0, 1}};
  matrix b = {{1, 0, 1}};
  while(t--){
    cin >> n >> m;
    if(n <= 1) cout << (b*exp(a, m-1))[0][2] << "\n";
    else{
      cout << sub((b*exp(a, m-1))[0][2], (b*exp(a, n-2))[0][2]) << "\n";
    }
  }
}

int main(){
  cout.precision(12);
  cout << fixed;
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  solve();
  cerr << "Time: " << 1.0*clock()/CLOCKS_PER_SEC << " s.\n";
#else
  ios::sync_with_stdio(false);cin.tie(0);
  solve();
#endif
}
