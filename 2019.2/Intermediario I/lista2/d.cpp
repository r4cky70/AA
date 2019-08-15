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

struct node{
  int zero, one, two;
  node(){
    zero = 1;
    one = 0;
    two = 0;
  }
  node(int a, int b, int c){
    zero = a;
    one = b;
    two = c;
  }
};

node oper(node a, node b){
  a.zero+=b.zero;
  a.one+=b.one;
  a.two+=b.two;
  return a;
}

struct segtree{
  node tree[MAXS*4];
  int lazy[MAXS*4];

  void push(int no, int l, int r){
    if(lazy[no]%3 == 1){
      swap(tree[no].zero, tree[no].one);
      swap(tree[no].zero, tree[no].two);
    }else if(lazy[no]%3 == 2){
      swap(tree[no].one, tree[no].two);
      swap(tree[no].zero, tree[no].two);
    }
    if(l != r){
      lazy[no<<1] += lazy[no];
      lazy[(no<<1)+1] += lazy[no];
    }lazy[no] = 0;
  }

  void build(int no, int l, int r){
    lazy[no] = 0;
    if(l == r){
      tree[no] = node();
    }else{
      int mid = (l+r)>>1;
      build(no<<1, l, mid);
      build((no<<1)+1, mid+1, r);
      tree[no] = oper(tree[no<<1], tree[(no<<1)+1]);
    }
  }

  void update(int no, int l, int r, int x, int y){
    if(l > y || r < x){
      push(no, l, r);
    }else if(l >= x && r <= y){
      lazy[no]++;
      push(no, l, r);
    }else{
      push(no, l, r);
      int mid = (l+r)>>1;
      update(no<<1, l, mid, x, y);
      update((no<<1)+1, mid+1, r, x, y);
      tree[no] = oper(tree[no<<1], tree[(no<<1)+1]);
    }
  }
  node query(int no, int l, int r, int x, int y){
    push(no, l, r);
    if(l > y || r < x){
      return node(0, 0, 0);
    }else if(l >= x && r <= y){
      return tree[no];
    }else{
      int mid = (l+r)>>1;
      return oper(query(no<<1, l, mid, x, y), query((no<<1)+1, mid+1, r, x, y));
    }
  }
}root;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  root.build(1, 0, n-1);
  int a, b, c;
  for(int i = 0 ; i < q; ++i){
    cin >> a >> b >> c;
    if(a == 0){
      root.update(1, 0, n-1, b, c);
    }else{
      cout << root.query(1,  0, n-1, b, c).zero << "\n";
    }
  }
}