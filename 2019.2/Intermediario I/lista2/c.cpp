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

struct node{
  ll bits[23];
  node(){
    memset(bits, 0,  sizeof bits);
  };
  node(int a){
    for(int  i = 22; i >-1; --i){
      bits[i] = a/(1<<i);
      a%=(1<<i);
    }
  }
};

node merge(node a, node b){
  node temp;
  for(int i = 0; i < 23; ++i){
    temp.bits[i] = a.bits[i] + b.bits[i];
  }
  return temp;
}

ll take(node a){
  ll ans = 0;
  for(int i = 22; i >-1; --i){
    ans += a.bits[i] * (1<<i);
  }
  return ans;
}


struct segtree{
  node tree[MAXS*4];
  ll lazy[MAXS*4];

  void push(int no, int l, int r){
    if(lazy[no] != -1){
      if(l != r){
        lazy[no*2] = (lazy[no*2] ==  -1 ? lazy[no] : lazy[no*2]^=lazy[no]);
        lazy[no*2+1] = (lazy[no*2+1] == -1 ? lazy[no] : lazy[no*2+1]^=lazy[no]);
      }
      for(int i = 22; i > -1; --i){
        if(lazy[no]/(1<<i)){
          tree[no].bits[i] = (r-l+1) - tree[no].bits[i];
        }
        lazy[no]%=(1<<i);
      }
      lazy[no] = -1;
    }
  }


  void build(int no, int l, int r){
    lazy[no] = -1;
    if(l == r){
      tree[no] = node(arr[l]);
    }else{
      int mid = (l+r)/2;
      build(no*2, l,  mid);
      build(no*2+1, mid+1, r);
      tree[no] = merge(tree[no*2],tree[no*2+1]); 
    }
  }
  void update(int no, int l, int r, int x, int y, int v){
    if(l > y || r < x){
      push(no, l, r);
    }else if(r <= y && l >= x){
      if(lazy[no] == -1) lazy[no] = v;
      else lazy[no]^=v;
      push(no, l, r);
    }else{
      push(no, l, r);
      int mid = (l+r)/2;
      update(no*2, l, mid, x, y, v);
      update(no*2+1, mid+1, r, x, y, v);
      tree[no] = merge(tree[no*2], tree[no*2+1]);
    }
  }
  node query(int no, int l, int r,  int x, int y){
    push(no, l, r);
    if(l > y || r <x){
      return node();
    }else if(r <= y && l >=x){
      return tree[no];
    }else{
      int mid  =  (l+r)/2;
      return merge(query(no*2, l, mid, x, y), query(no*2+1, mid+1, r, x, y));
    }
  }

}root;



int main(){
  cin >>  n;
  for(int i =  0 ; i <  n; ++i){
    cin >> arr[i];
  }
  cin >> q;
  root.build(1, 0, n-1);
  int  a, b, c, d;
  for(int i = 0; i < q;  ++i){
    cin >> a;
    if(a  == 1){
      cin >> b >> c;
      cout << take(root.query(1, 0, n-1, b-1, c-1)) << "\n";
    }else{
      cin >> b >> c >> d;
      root.update(1, 0, n-1, b-1, c-1, d);
    }
  }
}