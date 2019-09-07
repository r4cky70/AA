#include <bits/stdc++.h>
#define MAXS 100007
#define INF 2147483647

#define mp(a, b) make_pair(a,b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define STREE int bch = no*2, mid = (l+r)/2
#define all(a) a.begin(), a.end()

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int arr[MAXS];
int n;

struct segtree{
  int tree[4*MAXS];

  void build(int no, int l, int r){
    STREE;
    if(l == r) tree[no] = arr[l];
    else{
      build(bch, l, mid);
      build(bch+1, mid+1, r);
      tree[no] = max(tree[bch], tree[bch+1]);
    }
  }
  int query(int no, int l, int r, int x, int y, int v){
    if(l > y || r < x){
      return INF;
    }else if(l == r){
      if(arr[l] <= v) return INF;
      else return l;
    }else if(l >= x && r <= y){
      STREE;
      if(tree[no*2] > v) return query(bch, l, mid, x, y, v);
      else if(tree[bch] <= v && tree[bch+1] <= v){
        return INF;
      }else return query(bch+1, mid+1, r, x, y, v);
    }else{
      STREE;
      if(tree[no*2] > v) return query(bch, l, mid, x, y, v);
      else if(tree[bch] <= v && tree[bch+1] <= v){
        return INF;
      }else return query(bch+1, mid+1, r, x, y, v);
    }
  }
}root;


int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> arr[i];
  }
  root.build(1, 0, n-1);
  for(int i = 0; i < n-1; ++i){
    int a = root.query(1, 0, n-1, i+1, min(i+arr[i], n-1), arr[i]);
    cout << (a== INF ? min(i+arr[i], n-1)-i : a-i-1)<< " ";
  }cout << 0;
}