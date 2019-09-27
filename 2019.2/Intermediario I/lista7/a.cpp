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
const int MAXS = 300007;

int arr[MAXS];

void kmp(string s){
  int m = 0;
  arr[0] = 0;
  for(int i = 1; i < s.length(); ++i){
    if(1.0*clock()/CLOCKS_PER_SEC > 1.8)return;
    while(m > 0 && s[m] != s[i]){ m = arr[m];if(1.0*clock()/CLOCKS_PER_SEC > 1.8)return;}
    if(s[m] == s[i]) arr[i] = ++m;
  }
}

int check(string &s, int t){
  for(int i = 0; i < s.length(); ++i){
    if(1.0*clock()/CLOCKS_PER_SEC > 1.8)return false;
    if(arr[i] == t) return true;
  }
  return false;
}

void solve(){
  string s[3];
  cin >> s[0] >> s[1] >> s[2];
  sort(s, s+3);
  int ans = INF;
  int teste = 0;
  do{
    teste++;
    if(1.0*clock()/CLOCKS_PER_SEC > 1.8)break;
    assert(teste < 20);
    string temp = s[0];
    string aux = s[1]+'$'+s[0];
    kmp(aux);
    // debugarr(arr, aux.size());
    if(!check(aux, s[1].length())){
      temp += s[1].substr(arr[aux.length()-1], s[1].length());
    }
    if(1.0*clock()/CLOCKS_PER_SEC > 1.8)break;
    fill(arr, arr+aux.length(), 0);
    aux = s[2]+'$'+temp;
    kmp(aux);
    // debugarr(arr, aux.size());
    if(check(aux, s[2].length())){
      ans = min(ans, (int)temp.length());
    }else{
      ans = min(ans, (int)(temp.length()+s[2].length()-arr[aux.length()-1]));
    }
    if(1.0*clock()/CLOCKS_PER_SEC > 1.8)break;
    fill(arr, arr+aux.length(), 0);
    // int asj; cin >> asj;
  }while(next_permutation(s, s+3));
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