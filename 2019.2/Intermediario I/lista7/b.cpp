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
const int MAXS = 200007;

ll bmod[2] = {114559609, 114559639};
ll lmod[2] = {307, 317};

ll pot[2][MAXS];
ll inv[2][MAXS];
ll inverso;
ll rpot[2][MAXS];
ll rinv[2][MAXS];

ll adi(ll a, ll b, ll mod){
  return (a%mod + (b%mod))%mod;
}
ll multi(ll a, ll b, ll mod){
  return (a%mod * (b%mod))%mod;
}
ll fastexp(ll a, ll b, ll mod){
  if(b == 0) return 1;
  if(b == 1) return a%mod;
  ll x = fastexp(a, b/2, mod);
  if(b%2){
    return multi(multi(x, x, mod), a, mod);
  }else{
    return multi(x, x, mod);
  }
}

void prec(){
  for(int j = 0; j < 2; ++j){
    rpot[j][0] = pot[j][0] = 1;
    rinv[j][0] = inv[j][0] = 1;
    inverso = fastexp(lmod[j], bmod[j]-2, bmod[j]);
    for(int i = 1; i < MAXS; ++i){
      rpot[j][i] = pot[j][i] = multi(pot[j][i-1], lmod[j], bmod[j]);
      rinv[j][i] = inv[j][i] = multi(inv[j][i-1], inverso, bmod[j]);
    }
  }
}

struct hashing{
  ll chash[2][MAXS];
  ll rhash[2][MAXS];
  int tam;

  hashing(){tam = 0;}
  hashing(string s){
    tam = s.size();
    reverse(rinv[0], rinv[0]+tam);
    reverse(rpot[0], rpot[0]+tam);
    reverse(rinv[1], rinv[1]+tam);
    reverse(rpot[1], rpot[1]+tam);
    for(int j = 0; j < 2; ++j){
      chash[j][0] = multi(s[0], pot[j][0], bmod[j]);
      rhash[j][tam-1] = multi(s[tam-1], rpot[j][tam-1], bmod[j]);
      for(int i = 1; i < s.size(); ++i){
        chash[j][i] = adi(chash[j][i-1], multi((s[i]), pot[j][i], bmod[j]), bmod[j]);
      }
      for(int i = tam-2; i > -1; --i){
        rhash[j][i] = adi(rhash[j][i+1], multi(s[i], rpot[j][i], bmod[j]), bmod[j]);
      }
    }
  }

  pair<ll, ll> gethash(){
    return make_pair(chash[0][tam-1], chash[1][tam-1]);
  }

  bool operator ==(hashing &e){
    return gethash() == e.gethash();
  }
  
  pair<ll, ll> sub(int i, int j){ // [i, j]
    pair<ll, ll> ans;
    ans.first = (chash[0][j] + bmod[0] - (i==0?0:chash[0][i-1])) * inv[0][i] %bmod[0];
    ans.second = (chash[1][j] + bmod[1] - (i==0?0:chash[1][i-1])) * inv[1][i] %bmod[1];
    return ans;
  }
  pair<ll, ll> vol(int i, int j){
    pair<ll, ll> ans;
    ans.first = (rhash[0][i] + bmod[0] - (j==tam-1?0:rhash[0][j+1])) * rinv[0][j] %bmod[0];
    ans.second = (rhash[1][i] + bmod[1] - (j==tam-1?0:rhash[1][j+1])) * rinv[1][j] %bmod[1];
    return ans;
  }
  void teste(int i, int j){
    debugarr(chash[0], tam);
    debugarr(chash[1], tam);
    debugarr(rhash[0], tam);
    debugarr(rhash[1], tam);
    pair<ll, ll> temp = sub(i, j);
    cout << temp.first << " " << temp.second << endl;
    temp = vol(i, j);
    cout << temp.first << " " << temp.second << endl;
  }
};

string s;
int n, a, b, c, d;

void solve(){
  prec();
  cin >> s;
  hashing h = hashing(s);
  cin >> n;
  h.teste(0, 4);

  for(int i = 0; i < n; ++i){
    cin >> a >> b >> c >> d;
    if(a > d || b < c){
      cout << (h.sub(c-1, d-1) == h.vol(c-1, d-1) ? "YES\n":"NO\n") << endl;
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