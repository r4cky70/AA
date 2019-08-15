#include <bits/stdc++.h>
#define MAXS 200007
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
ll arr[MAXS];

vi split(string s){
  vi a;
  string temp = "";
  for(int i = 0; i < s.size(); ++i){
    if(s[i] == ' '){
      a.pb(stoi(temp));
      temp = "";
    }else{
      temp+=s[i];
    }
  }if(temp.size() > 0) a.pb(stoi(temp));
  return a;
}


struct segtree{
  ll tree[MAXS*4];
  ll lazy[MAXS*4];

  void push(int no, int l, int r){
    tree[no] += lazy[no];
    if(l != r){
      lazy[no*2] += lazy[no];
      lazy[no*2+1] += lazy[no];
    }
    lazy[no] = 0;
  }

  void build(int no, int l, int r){
    if(l == r){
      tree[no] = arr[l];
    }else{
      int mid = (l+r)/2;
      build(no*2, l, mid);
      build(no*2+1, mid+1, r);
      tree[no] = min(tree[no*2], tree[no*2+1]);
    }
  }
  void update(int no, int l, int r, int x, int y, int v){
    if(l > y ||  r < x){
      push(no, l, r);
    }else if(l >= x && r <= y){
      lazy[no] += v;
      push(no, l, r);
    }else{
      push(no, l, r);
      int mid = (l+r)/2;
      update(no*2, l, mid, x, y, v);
      update(no*2+1, mid+1, r, x, y, v);
      tree[no] = min(tree[no*2], tree[no*2+1]);
    }  
  }
  ll query(int no, int l, int r, int x, int y){
    push(no, l, r);
    if(l > y || r < x){
      return INF*INF;
    }else if(l >= x && r <= y){
      return tree[no];
    }else{
      int mid = (l+r)/2;
      return min(query(no*2, l, mid, x, y),  query(no*2+1, mid+1, r, x, y));
    }
  }
}root;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(int i = 0 ; i < n; ++i){
    cin >> arr[i];
  }
  cin >> q;
  root.build(1, 0, n-1);
  string s;
  cin.ignore();
  for(int i = 0; i < q; ++i){
    // cout << idk.size() << "caraioooo\n";
    getline(cin, s);
    vi idk = split(s);
    // cout << idk.size() << " idk.size\n";
    if(idk.size() == 2){
      int a = idk[0], b = idk[1];
      if(a > b){
        cout << min(root.query(1, 0, n-1, a, n-1), root.query(1, 0, n-1, 0, b)) << "\n";
      }
      else{
        cout << root.query(1, 0, n-1, a, b) << "\n";
      }
    }else{
      int a = idk[0], b = idk[1], c = idk[2];
      if(a > b){
        root.update(1, 0, n-1, a, n-1, c); root.update(1, 0, n-1, 0, b, c);
      }else{
        root.update(1, 0, n-1, a, b, c);
      }
    }
  }

}