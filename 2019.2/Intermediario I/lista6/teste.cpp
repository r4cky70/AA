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
int MOD = 1000000007;

int extended_euclidean(int a, int b, int & x, int & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = extended_euclidean(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

void solve(){
  int a, b;
  cin >> a >> b;
  int x, y;
  int g = extended_euclidean(a, b, x, y);
  cout << g << " " << x << " " << y << endl;
  x = (x%b+b)%b;
  cout << x << endl;
  
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
