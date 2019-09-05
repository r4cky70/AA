#include <bits/stdc++.h>
#define MAXS 500007
#define INF 2147483647

#define mp(a, b) make_pair(a,b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define STREE int branch = no*2, mid = (l+r)/2
#define all(a) a.begin(), a.end()

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;

unordered_map<int , ll> r;
unordered_map<int, ll> c;


int main(){
  FASTIO;
  int t;
  cin >> t;
  while(t--){
    cin >> n;
    ll a, b;
    r.clear();c.clear();
    for(int i =0 ; i < n; ++i){
      cin >> a >> b;
      r[a]++; c[b]++;
    }
    ll ans = 0;
    for(auto it = r.begin(); it!=r.end(); ++it){
      ans+=(*it).second * c[(*it).first];
    }
    cout << ans << "\n";
  }
}