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

ll n, q;
ll arr[MAXS]; 
ll jump[MAXS], last[MAXS], lim[MAXS];
ll sq;


void li(){
  for(int i = 0; i < n; ++i){
    lim[i] = min(sq*(i/sq) + sq-1, n-1);
  }
}

void build(ll i){
  ll id = i;
  jump[i] = last[i] = 0;
  if(id+arr[id] <= lim[i]){
    jump[i] = jump[id+arr[id]]+1;
    last[i] = last[id+arr[id]];
  }else{
    jump[i] = 1;
    last[i] = i;
  }
}

void update(ll id, int v){
  ll temp = lim[id];
  arr[id] = v;
  for(int i = id; i >= temp-sq-1; --i){
    build(i);
  }
}

pair<long, long> query(ll id){
  ll ans = 0;
  ll l = 0;
  do{
    ans += jump[id];
    id = last[id];
    l = id;
    id += arr[id];
  }while(id < n);
  return mp(l, ans);
}

int main(){
  FASTIO;
  // INP; OUT;
  cin >> n >> q;
  sq = sqrt(MAXS);
  for(register int i =0; i < n; ++i){
    cin  >> arr[i];
  }
  li();
  for(register int i = n-1; i > -1; --i){
    last[i] = i;
    build(i);

  }
  ll a, b, c;
  while(q--){
    cin >> a;
    if(a == 0){
      cin >> b >> c;
      update(b-1, c);
    }else{
      cin >> b;
      pair<long, long> ans = query(b-1);
      cout << ans.first+1 << " " << ans.second << "\n";
    }
  }
} 