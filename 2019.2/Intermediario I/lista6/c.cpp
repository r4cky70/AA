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
const int MAXS = 1000007;

ll modinv(ll a, ll m) {
	// assert(m > 0);
	if (m == 1) return 0;
	a %= m;
	if (a < 0) a += m;
	// assert(a != 0);
	if (a == 1) return 1;
	return m - modinv(m, a) * m / a;
}

template <int MOD> class modnum{
public:
  ll v;
  modnum() : v(0){}
  modnum(ll p){v = p%MOD;}
  bool operator == (modnum& o) {return this.v == o.v;}
  bool operator != (modnum& o) {return this.v != o.v;}
  friend ostream& operator << (ostream& os, const modnum& mn) {
    os << mn.v;
    return os;
  }
  friend istream& operator >> (istream& is, modnum& mn) {
    is >> mn.v;
    return is;
  }
  modnum operator + (ll o) {return (v+o)%MOD;}
  modnum operator - (ll o) {return ((v-o)%MOD+MOD)%MOD;}
  modnum operator * (ll o) {return (v*o)%MOD;}
  modnum operator / (ll o) {return (v * modinv(o, MOD));}
  modnum operator ~() const {
		modnum res;
		res.v = modinv(v, MOD);
		return res;
	}
	modnum& operator += (const modnum& o) {v = (v+o.v)%MOD;return *this;}
	modnum& operator -= (const modnum& o) {v = ((v-o.v)%MOD+MOD)%MOD;return *this;}
	modnum& operator *= (const modnum& o) {v = (v*o.v)%MOD;return *this;}
	modnum& operator /= (const modnum& o) {return *this *= (~o);}
 
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
using num=modnum<1000000007>;

char a, b;
int n;
num fact[MAXS];

bool check(string s){
  for(int i = 0; i < s.size(); ++i){
    if(s[i] != a && s[i] != b) return false;
  }return true;
}
num comb(ll n, ll s){
  num a(n), b(s);
  num temp = ~(fact[s] * fact[n-s]);
  return fact[n] * temp;
}


void prep(){
  fact[0] = 1;
  for(int i = 1; i <= n; ++i){
    fact[i] = fact[i-1] * i;
  }
}

void solve(){
  prep();
  cin >> a >> b >> n;
  string s(n, a);
  int tot = (a-'0')*n;
  num ans = 0;
  if(check(to_string(tot))) ans+=1;
  for(int i = 0; i < n; ++i){
    s[i] = b;
    tot += b-a;
    if(check(to_string(tot))){
      ans += comb(n, i+1);
    }
  }
  cout << "hello\n";
  cout << ans << "\n";

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
