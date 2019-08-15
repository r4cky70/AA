#include <bits/stdc++.h>
#define MAXS 100007
#define INF 2234567890

#define make_pair(a, b) mp(a,b)
#define pb push_back
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;

int n, q;
int arr[MAXS];

vi merge(vi a, vi b){
  vi ans;
  if(a.size() == 0) return b;
  else if(b.size() == 0) return a;
  int p1 = 0, p2  = 0;
  while(p1 < a.size() || p2 < b.size()){
    if(p1 == a.size()){
      ans.pb(b[p2]);
      ++p2;
    }else if(p2 == b.size()){
      ans.pb(a[p1]);
      ++p1;
    }else if(a[p1] < b[p2]){
      ans.pb(a[p1]);
      ++p1;
    }else{
      ans.pb(b[p2]);
      ++p2;
    }
  }
  return ans;
}



struct mergetree{
  vi tree[MAXS];

  void build(int no, int l, int r){
    if(l == r){
      tree[no].pb(arr[l]);
    }else{
      int mid = (l+r)/2;
      build(no*2, l, mid);
      build(no*2+1, mid+1, r);
      tree[no] = merge(tree[no*2], tree[no*2+1]);
    }
  }
  vi query(int no, int l, int r, int x, int y){
    if(l > y || r < x){
      vi ans;
      return ans;
    }else if(l >=  x &&  r <=  y){
      return tree[no];
    }else{
      int mid = (l+r)/2;
      return  merge(query(no*2, l, mid, x, y), query(no*2+1, mid+1, r, x, y));
    }
  }

}root;

int main(){
  // INP;OUT;
  INP;
  clock_t st = clock();
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> q;
  for(int i = 0; i < n; ++i){
    cin >> arr[i];
  }
  root.build(1, 0, n-1);
  int a, b, c;
  for(int i = 0 ; i < q; ++i){
    cin >> a >> b >> c;
    cout << root.query(1, 0, n-1, a-1, b-1)[c-1] << "\n";
  }
  clock_t en = clock();
  cout << (double)(en-st)/CLOCKS_PER_SEC << endl;
}