#include <bits/stdc++.h>
#define MAXS 100007
#define INF 2147483647

#define mp(a, b) make_pair(a,b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define STREE int bch = no*2, mid = (l+r)/2
#define ALL(a) a.begin(), a.end()

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int arr[MAXS];
int n, q;
int spt[MAXS][26];
map<int, int> ans;

void build(){
  for(int i = 0;i < n; ++i) spt[i][0] = arr[i];
  for(int i = 1; (1<<i) <= n; ++i){
    for(int j = 0; j + (1<<i)<=n;++j){
      spt[j][i] = __gcd(spt[j][i-1], spt[j+(1<<i-1)][i-1]);
    }
  }
}
int query(int l, int r){
  if(l>r) swap(l, r);
  int lg = __builtin_clz(1) - __builtin_clz(r-l+1);
  return __gcd(spt[l][lg], spt[r-(1<<lg)+1][lg]);
}

void busca(int be, int en){
  int l = be;
  int r = en;
  while(l < r){
    int v = query(be, l);
    // cout << v << endl;
    int p = l;
    while(l != r){
      int mid = (l+r)/2;
      // cout << l << " " << mid << " " << r << " query=" << query(be, mid) <<  endl;
      if(query(be, mid) == v) l = mid+1;
      else r = mid;
    }
    // cout << r << " " << p << " ola\n";
    // cout << r-p << " valor, " << v << "\n";
    if(r == en) ans[v]+=r-p+1;  
    else ans[v]+=r-p;
    r = en; 
  }
}


void solve(){
  // busca(0, n-1);
  for(int i = 0; i < n; ++i){
    busca(i, n-1);
  }
}


int main(){
  INP;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> arr[i];
  }
  cin >> q;
  build();
  solve();
  int a;
  while(q--){
    cin >> a;
    cout << ans[a] << "\n";
  }
}