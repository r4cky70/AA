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
const int MOD = 1000000000;

typedef vector<vector<ll>> matrix;

ll b[20], c[20];
ll t, n, k;

ll adi(ll a, ll b){
  return (a%MOD +(b%MOD))%MOD;
}

ll multi(ll a, ll b){
  return (a%MOD * (b%MOD))%MOD;
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
				s = adi(multi(a[i][k], col[k]), s);
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
  if(b%2) c = c*a;
  return c;
}

void printmatrix(matrix a){
  for(int i = 0; i < a.size(); ++i){
    for(int j = 0; j < a[0].size(); ++j){
      cout << a[i][j] << " ";
    }cout << "\n";
  }
}

void solve(){
  cin >> t;
  while(t--){
    cin >> k;
    for(int i = 0; i < k; ++i){
      cin >> b[i];
    }
    for(int i = 0; i < k; ++i){
      cin >> c[i];
    }
    cin >> n;
    if(n <= k) cout << b[n-1] << "\n";
    else{
      matrix base(1, vector<ll>(k));
      for(int i = 0; i < k; ++i){
        base[0][i] = b[i];
      }
      matrix u(k, vector<ll>(k));
      for(int i = 1; i < k; ++i){
        u[i][i-1] = 1;
      }
      for(int i = 0; i < k; ++i){
        u[i][k-1] = c[k-1-i];
      }
      matrix ans = (base*exp(u, n-k));
      cout << ans[0][k-1] << "\n";
      
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