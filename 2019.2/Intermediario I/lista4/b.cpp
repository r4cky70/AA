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

int t, n, q;
ll arr[MAXS];
ll sq;

ll lazy[MAXS];
ll sqr[MAXS];

void build(){
  fill(sqr, sqr+n, 0);
  fill(lazy, lazy+n, 0);
}

ll prop(int l, int r, int v){
  ll ans = 0;
  int buck = l/sq*sq;
  for(int i = buck; i < buck+sq; ++i){
    arr[i] += lazy[buck/sq];
    if(i >= l && i <= r){
      arr[i]+=v;
      ans+=arr[i];
    }
  }
  lazy[buck/sq] = 0;
  return ans;
}

void update(ll l, ll r, ll v){
  while(l <= r){
    int buck = l/sq;
    if(l%sq || r-l < sq){
      prop(l, r, v);
      sqr[buck] += (buck == r/sq ? r-buck*sq+1 : (buck*sq+sq)-l)*v;
      l = buck*sq+sq;
    }else{
      sqr[buck] += v*sq;
      lazy[buck] += v;
      l+=sq;
    }
  }
}

ll query(ll l, ll r){
  ll ans = 0;
  while(l <= r){
    int buck = l/sq;
    if(l%sq || r-l < sq){
      ans += prop(l, r, 0);
      l = buck*sq+sq;
    }else{
      ans += sqr[buck];
      l += sq;
    }
  }
  return ans;
}


int main(){
  cin >> t;
  sq = sqrt(MAXS);
  while(t--){
    cin >> n >> q;
    int a, b, c, d;
    build();
    while(q--){
      cin >> a;
      if(a == 0) {
        cin >> b >> c >> d;
        update(b-1, c-1, d);
      }else{
        cin >> b >> c;
        cout << query(b-1, c-1) << "\n";
      }
    }
  }
}