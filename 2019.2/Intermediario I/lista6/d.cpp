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
int MOD;

bitset<MAXS> cri;
vector<int> prims;

ll multi(ll a, ll b){
  return (a%MOD * (b%MOD)%MOD);
}

void sieve(){
  cri.set();
  cri[0] = 0;
  cri[1] = 0;
  for(int i = 2; i < MAXS; ++i){
    if(cri[i]){
      for(int j = i+i; j < MAXS; j+=i){
        cri[j] = 0;
      }
      prims.pb(i);
    }
  }
}

int getit(int n){
  for(int i = 0; i < prims.size(); ++i){
    if(n%prims[i] == 0){
      return prims[i];
    }
  }
}

ll fe(ll a, ll b){
  if(b == 0) return 1;
  if(b%2 == 0){
    ll x = fe(a, b/2);
    return multi(x,  x);
  }
  return multi(fe(a, b - 1), a);
}

int exgcd(int a, int b, int &x, int &y){
  if(a == 0){
    x = 0;
    y = 1; 
    return b;
  }
  int x1, y1;
  int d = exgcd(b%a, a, x1, y1);
  x = y1 - (b/a) * x1;
  y = x1;
  return d;
}


void solve(){
  ll n, e, c;
  sieve();
  while(cin >> n){
    cin >> e >> c;
    MOD = n;
    ll x = getit(n);
    ll y = n/x;
    ll t = (x-1)*(y-1);
    int b, z;
    int g = exgcd(e, t, b, z);
    // debug(b);
    b = (b % t + t) % t;
    MOD = n;
    // debug(b);
    cout << fe(c, b) << endl;
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
