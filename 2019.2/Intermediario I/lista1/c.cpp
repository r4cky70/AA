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

int n;
int arr[MAXS];
vi temp;

pii oper(pii a, pii b){
  temp.clear();
  temp.push_back(a.first); temp.push_back(a.second); temp.push_back(b.first); temp.push_back(b.second);
  sort(temp.begin(), temp.end());
  return mp(temp[2], temp[3]);
}



struct segtree{
  pair<int, int> tree[MAXS*4];
  
  void build(int no, int l, int r){
    if(l == r) tree[no] = mp(arr[l], -INF);
    else{
      int mid = (l+r)/2;
      build(no*2, l, mid);
      build(no*2+1, mid+1, r);
      tree[no] = oper(tree[no*2], tree[no*2+1]);
    }
  }
  void update(int no, int l, int r, int ind, int v){
    if(l == r) tree[no] = mp(v, -INF);
    else{
      int mid = (l+r)/2;
      if(ind > mid){
        update(no*2+1, mid+1, r, ind, v);
      }else{
        update(no*2, l, mid, ind, v);
      }
      tree[no] = oper(tree[no*2], tree[no*2+1]);
    }
  }
  pii query(int no, int l, int r, int x, int y){
    if(x > r || y < l) return mp(-INF, -INF);
    else if(l>=x && r <=y) return tree[no];
    else{
      int mid = (l+r)/2;
      return oper(query(no*2, l, mid, x, y), query(no*2+1, mid+1, r, x, y));
    }
  }
}root;



int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> arr[i];
  }
  root.build(1, 0, n-1);
  int t;
  cin >> t;
  char c; int a, b;
  for(int i = 0 ; i < t; ++i){
    cin >> c >> a >> b;
    if(c == 'U'){
      root.update(1, 0, n-1, a-1, b);
    }else{
      pii ans = root.query(1, 0, n-1, a-1, b-1);
      cout << ans.first + ans.second << "\n";
    }
  }
}