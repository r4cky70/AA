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

int n, q;
int arr[MAXS];
int sq;
int last[MAXS], jump[MAXS];

void build(int id){
  int buck = id/sq;
  if(id+arr[id] >= n || (id+arr[id])/sq > buck){
    last[id] = id;
    jump[id] = 1;
  }else{
    last[id] = last[id+arr[id]];
    jump[id] = jump[id+arr[id]]+1;
  }
}

void update(int id, int v){
  arr[id] = v;
  for(int i = id; i >= (id/sq)*sq; --i){
    build(i);
  }
}

pii query(int id){
  int ans = 0;
  int l = 0;
  while(id < n){
    l = last[id];
    if(last[id] != id){
      ans += jump[id];
      id = last[id]+arr[last[id]];
    }else{
      ans += jump[id];
      id += arr[id];
    }
  }
  return mp(l, ans);
}


int main(){
  FASTIO;
  cin >> n >> q;
  sq = sqrt(MAXS);

  for(int k = 0; k < n; ++k){
    cin >> arr[k];
  }
  for(int i = n-1; i >= 0; --i) build(i);
  int a, b, c;
  while(q--){
    cin >> a;
    if(a == 1){
      cin >> b;
      pii ans = query(b-1);
      cout << ans.first+1 << " " << ans.second << "\n";
    }else{
      cin >> b >> c;
      update(b-1, c);
    }
  }
}