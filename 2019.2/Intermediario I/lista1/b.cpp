#include <bits/stdc++.h>
#define INF 1234567890
#define MAXS 100007

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, t;

int arr[MAXS];

int oper(int a, int b){
  if(a == 0 || b == 0){
    return 0;
  }else if(a >= 1) return b;
  else return -b;
}



struct segtree{
  int tree[MAXS*4];

  void build(int node, int left, int right){
    if(left == right){
      tree[node] = arr[left];
    }else{
      int mid = (left+right)/2;
      build(node*2, left, mid);
      build(node*2+1, mid+1, right);
      tree[node] = oper(tree[node*2], tree[node*2+1]);
    }
  }
  void update(int node, int left, int right, int ind, int v){
    int mid = (left+right)/2;
    if(left == right) {
      tree[node] = v;
    }else if(ind > mid){
      update(node*2+1, mid+1, right, ind, v);
      tree[node] = oper(tree[node*2], tree[node*2+1]);
    }else{
      update(node*2, left, mid, ind, v);
      tree[node] = oper(tree[node*2], tree[node*2+1]);
    }
  }
  int query(int node, int left, int right, int x, int y){
    if(x > right || y < left) return 1;
    else if(left >= x && right <= y){
      return tree[node];
    }else{
      int mid = (left+right)/2;
      return oper(query(node*2, left, mid, x, y), query(node*2+1, mid+1, right, x, y));
    }
  }
}root;


char hello(int a){
  if(a > 0) return '+';
  else if (a < 0) return '-';
  return '0';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  // INP; OUT;
  while(cin >> n){
    cin >> t;
    for(int i = 0;i < n; ++i){
      cin >> arr[i];
    }
    root.build(1, 0, n-1);
    char c; int a, b;
    for(int i = 0; i < t; ++i){
      cin >> c >> a >> b;
      if(c == 'C'){
        root.update(1, 0, n-1, a-1, b);
      }else{
        cout << hello(root.query(1, 0, n-1, a-1, b-1));
      }
    }
    cout << endl;
  }
}