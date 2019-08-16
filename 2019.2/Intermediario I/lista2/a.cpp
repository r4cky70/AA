#include <bits/stdc++.h>
#define MAXS 100007
#define INF 2234567890

#define make_pair(a, b) mp(a,b)
#define pb push_back
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define STREE int bch = no*2, mid = (l+r)/2
#define all(a) a.begin(), a.end()

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pair<ll, ll > > vpii;


int n, q;
pii so[MAXS];
int arr[MAXS];

struct segtree{
  vi tree[MAXS*4];

  void build(int no, int l, int r){
    if(l==r){
      tree[no].pb(so[l].second);
    }else{
      int mid = (l+r)/2;
      build(no*2, l, mid);
      build(no*2+1, mid+1, r);
      merge(tree[no*2].begin(), tree[no*2].end(), tree[no*2+1].begin(), tree[no*2+1].end(), back_inserter(tree[no]));
    }
  }
  int query(int no, int l, int r, int x, int y, int v){
    if(l == r) return arr[tree[no][0]];
    int a = upper_bound(tree[no*2].begin(), tree[no*2].end(), y) - lower_bound(tree[no*2].begin(), tree[no*2].end(), x);
    int mid = (l+r)/2;
    if(a >= v){
      return query(no*2, l, mid, x, y, v);
    }else return query(no*2+1, mid+1, r, x, y, v-a);
  }
}root;



int main(){
  cin >> n >> q;
  for(int i = 0; i < n; ++i){
    cin >> arr[i];
    so[i] = {arr[i], i};
  }
  sort(so, so+n);
  root.build(1, 0, n-1);
  int a, b, c;
  for(int i = 0; i < q; ++i){
    cin >> a >> b >> c;
    cout << root.query(1, 0, n-1, a-1, b-1, c) << "\n";
  }
}


