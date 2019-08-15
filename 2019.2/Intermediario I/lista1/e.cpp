#include <bits/stdc++.h>
#define INF 1234567890
#define MAXS 200007

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

int n, q;

struct node{
  int lm;
  int lmv;
  int rm;
  int rmv;
  int mst;
  int mstv;
  node(int a, int b, int c, int d, int e, int f){
    lm = a; lmv = b; rm = c; rmv = d; mst = e; mstv = f;
  }
  node(){
    lm = -1; lmv = -1; rm = -1; rmv = -1; mst = -1; mstv  = -1;
  }
};

int arr[MAXS];

node oper(node a, node b){
  int ca = INF;
  int c = -1;
  if(a.rm == b.lm){
    c = a.rmv + b.lmv;
    ca = a.rm;
    if(a.lm == b.lm){
      a.lmv = c;
    }if(b.rm == a.rm){
      b.rmv = c;
    }
  }
  int mt;
  int mtv;
  if(max(a.mstv, b.mstv) == a.mstv) {
    mt = a.mst;
    mtv = a.mstv;
  }else{
    mt = b.mst;
    mtv = b.mstv;
  }
  if(max(mtv, c) == c) {
    mt = ca;
    mtv = c;
  }
  return node(a.lm, a.lmv, b.rm, b.rmv, mt, mtv);
}


struct segtree{
  node tree[MAXS*4];

  void build(int no, int l, int r){
    if(l == r){
      tree[no] = node(arr[l], 1, arr[l], 1, arr[l], 1);
    }else{
      int mid = (l+r)/2;
      build(no*2, l, mid);
      build(no*2+1, mid+1, r);
      tree[no] = oper(tree[no*2], tree[no*2+1]);
    }
  }
  node query(int no,  int l, int r,  int x, int y){
    if(l >= x && r <= y){
      return tree[no];
    }else if(x > r  || y < l){
      return node();
    }else{
      int mid = (l+r)/2;
      return oper(query(no*2, l, mid, x, y), query(no*2+1, mid+1, r, x, y));
    }
  }
}root;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  while(cin >> n, n != 0){
    cin >> q;
    int a, b;
    for(int i = 0; i < n; ++i){
      cin >> arr[i];
    }
    root.build(1, 0, n-1);
    for(int i = 0 ; i < q;  ++i){
      cin >> a >> b;
      cout << root.query(1, 0, n-1, a-1, b-1).mstv << "\n";
    }

  }
}