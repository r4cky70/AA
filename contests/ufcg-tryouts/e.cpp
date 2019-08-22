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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
ll arr[MAXS];

struct mergetree{
  vector<long long> tree[MAXS*4];

  void build(int no, int l, int r){
    if(l == r) tree[no].push_back(arr[l]);
    else{
      STREE;
      build(branch, l, mid);
      build(branch+1, mid+1, r);
      merge(all(tree[branch]), all(tree[branch+1]), back_inserter(tree[no]));;
    }
  }
  bool query(int no, int l, int r, int x, int y, ll v){
    if(l > y || r < x){
      return 0;
    }else if(l >= x && r <= y){
      return binary_search(all(tree[no]), v);
    }else{                                                                           
      STREE;
      return max(query(branch, l, mid, x, y, v), query(branch+1, mid+1, r, x, y, v));
    }
  }
}root;

vector<long long> idk;

int main(){
  cin >> n;
  ll tot = 0;
  ll tot2 = 0;
  for(int i = 0; i < n; ++i){
    cin >> arr[i];
    tot += arr[i];
    tot2+=arr[i];
  }
  root.build(1, 0, n-1);
  tot-=arr[0];
  ll acu = arr[0];
  for(int i = 1; i < n; ++i){
    if((tot - acu)%2 == 0){
      idk.pb((tot-acu)/2);
    }
    else idk.pb(1LL*-INF*INF);
    tot-=arr[i];
    acu+=arr[i];
  }
  bool flag = false;
  for(int i = 0; i < idk.size(); ++i){
    if(idk[i] == 0) flag = true;
    else if(idk[i] > 0) flag = root.query(1, 0, n-1, i+1, n, idk[i]);
    else if(idk[i] == 1LL*-INF*INF) continue;
    else if(idk[i] < 0) flag = root.query(1, 0, n-1, 0, i-1, -idk[i]);
    if(flag == true) break;
  }
  if(flag == false)
  for(int i = 1; i < n-1; ++i){
    if(tot2-arr[i] == arr[i]){flag = true; break;}
  }
  cout << (flag ? "YES\n" : "NO\n");
}