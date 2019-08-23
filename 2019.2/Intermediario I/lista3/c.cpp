#include <bits/stdc++.h>
#define MAXS 10000007
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int arr[MAXS], bit[MAXS];
int t, n;

void update(int id, int v){
  while(id<MAXS){
    bit[id]+=v;
    id+=id&-id;
  }
}
ll query(int id){
  ll ans = 0;
  while(id > 0){
    ans+=bit[id];
    id-=id&-id;
  }
  return ans;
}


int main(){
  cin >> t;
  while(t--){
    memset(bit, 0, sizeof bit);
    memset(arr, 0, sizeof arr);
    cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
      cin >> arr[i];
    }
    for(int i = n; i > 0; --i){
      ans += query(arr[i]-1);
      update(arr[i], 1);
    }
    cout << ans << "\n";
  }
}