#include <bits/stdc++.h>
#define MAXS 100007
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

int t, n ,m;
ll arr[MAXS];
ll res[MAXS];
ll acu[MAXS];

ll check(ll a){
  ll ans = 0;
  while(a > 1){
    if(a&1)++ans;
    a=(a>>1);
    if(a==0) break;
    ++ans;
    // cout << a << " " << ans <<  endl;
  }
  return ans;
}


int main(){
  FASTIO;
  cin >> t;
  while(t--){
    cin >> n >> m;
    fill(acu, acu+n+4, 0);
    for(int i = 0; i < n; ++i){
      cin >> arr[i];
      res[i] = check(arr[i]);
      // cout << res[i] << "yo resultado\n";
    }
    acu[1] = res[0];
    for(int i = 2; i <= n; ++i){
      acu[i] = res[i-1] + acu[i-1];
    }
    // for(int i = 0; i < n; ++i) cout << acu[i] << " ";
    // cout << endl;
    int a, b;
    for(int i = 0; i < m; ++i){
      cin >> a >> b;
      cout << acu[b] - acu[a-1] << "\n";
    }
  }
}