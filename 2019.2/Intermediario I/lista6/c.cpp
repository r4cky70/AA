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
const int MOD = 1000000007;

char a, b;
int n;
ll fact[MAXS];
string s;

ll adi(ll a, ll b){
  return ((a%MOD) + (b%MOD)) %MOD;
}
ll mod(ll a) {return (a%MOD+MOD)%MOD;}
ll fe(ll a, ll b){
  if(b == 0) return 1;
  if(b%2 == 0){
    ll x = fe(a, b/2);
    return mod(x * x);
  }
  return mod(fe(a, b - 1) * a);
}
ll inv(ll a, ll b){
  return mod(a * fe(b, MOD-2));
}

bool isgood(string s){
  for(int i = 0; i < s.size(); ++i){
    if(s[i] != a && s[i] != b) return false;
  }
  return true;
}

ll comb(ll n, ll s){
  return mod(fact[n] * fe(mod(fact[s] * fact[n-s]), MOD-2));
  // return inv(fact[n], multi(fact[s], fact[n - s]));
}

void prep(){
  fact[0] = 1;
  for(int i = 1; i <= n; ++i){
    fact[i] = mod(fact[i-1] * i);
  }
}

void solve(){
  cin >> a >> b;
  cin >> n;
  prep();
  int ans = 0;
  int acu = n*(a-'0');
  if(isgood(to_string(acu))) ++ans;
  for(int i = 0; i < n; ++i){
    acu += b-'0'-(a-'0');
    if(isgood(to_string(acu))) ans = adi(ans, comb(n, i+1));
  }
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
