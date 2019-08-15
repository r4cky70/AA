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

int n, rep, aft, bef, q;

struct tipo{
  int aft;
  int bef;
  tipo(){
    aft = 0; bef = 0;
  }
  tipo(int a, int b){
    aft = a; bef = b;
  }
};

tipo tree[4*MAXS];
int arr[MAXS];

void update(int no, int l, int r, int x, int v){
  if(l == r){
    tree[no].aft = min(bef, arr[l]);
    tree[no].bef = min(aft, arr[l]);
  }else{
    int mid = (l+r)/2;
    if(x > mid) update(no*2+1, mid+1, r, x, v);
    else update(no*2, l, mid, x, v);
    tree[no].aft = tree[no*2].aft + tree[no*2+1].aft;
    tree[no].bef = tree[no*2].bef + tree[no*2+1].bef;
  }
}
int query(int no, int l, int r, int x, int y, int o){
    if(o == 1){
      if(x > r || y < l){
        return 0;
      }else if(l>=x && r <= y){
        return tree[no].aft;
      }else{
        int mid = (l+r)/2;
        return query(no*2, l, mid, x, y, o) + query(no*2+1, mid+1, r, x, y, o);
      }
    }else{
      if(x > r || y < l){
        return 0;
      }else if(l>=x && r <= y){
        return tree[no].bef;
      }else{
        int mid = (l+r)/2;
        return query(no*2, l, mid, x, y, o) + query(no*2+1, mid+1, r, x, y, o);
      }
    }
}


int main(){
  cin >> n >> rep >> aft >> bef >> q;
  int a, b, c;
  for(int k = 0; k < q; ++k){
    cin >> c;
    if(c == 1){
      cin >> a >> b;
      arr[a-1] += b;
      update(1, 0, n-1, a-1, b);
    }else{
      cin >> a;
      int ans = 0;
      if(a > 1) ans += query(1, 0, n-1, 0, a-2, 1);
      if(a + rep <= n) ans += query(1, 0, n-1, a-1+rep, n-1, 2);
      cout << ans << "\n";
    }
  }
}
