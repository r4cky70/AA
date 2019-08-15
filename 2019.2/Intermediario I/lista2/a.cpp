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
typedef vector < pii > vpii;

int n, q;
pii arr[MAXS];
 

bool func(pii a, pii b){
  return a.second < b.second;
}

vpii merge(vpii a, vpii b){
  vpii temp;
  int p1 = 0, p2 = 0;
  while(p1 != a.size() || p2 != b.size()){
    if(p1 == a.size()){
      temp.push_back(b[p2]);
      ++p2;    
    }else if(p2 == b.size()){
      temp.push_back(a[p1]);
      ++p1;
    }
    else if(a[p1].first < b[p2].first){
      temp.pb(a[p1]);
      ++p1;
    }else{
      temp.pb(b[p2]);
      ++p2;
    }
  }
  return temp;
}

int mylower(vpii a, int l, int r, int v){
  int mid = (l+r)/2;
  if(l == r) return l;
  else if(a[mid].first >= v){
    return mylower(a, l, mid, v);
  }else{
    return mylower(a, mid+1, r, v);
  }
}
int myupper(vpii a, int l,int r, int v){
  int mid = (l+r)/2;
  if(l == r) return l;
  else if(a[mid].first <= v){
    return myupper(a, mid+1, r, v);
  }else{
    return myupper(a, l, mid, v);
  }
}
bool funci(pii a, pii b){
  return (a.first < b.first);
}


struct mergetree{
  vpii tree[MAXS];

  int busca(int no, int l, int r, int x, int y){
    return lower_bound(tree[no].begin(), tree[no].end(), x, funci);
    return (l+r+1) - mylower(tree[no], l, r, x) - myupper(tree[no], l, r, y);
  }
  void build(int no, int l, int r){
    if(l == r){
      tree[no].push_back(arr[l]);
    }else{
      int mid = (l+r)/2;
      build(no*2, l, mid);
      build(no*2+1, mid+1, r);
      tree[no] = merge(tree[no*2], tree[no*2+1]);
    }
  }
  int query(int no, int l, int r, int x, int y, int v){
    if(l == r) return tree[no][0].second;
    int mid = (l+r)/2;
    int a = busca(no*2, l, mid, x, y);
    int b = busca(no*2+1, mid+1, r, x, y);
    if(v > a) return query(no*2+1, mid+1, r, x, y, v-a);
    else return query(no*2, l, mid, x, y, v);
  }

}root;

int main(){
  // INP;OUT;
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int temp;
  cin >> n >> q;
  for(int i = 0; i < n; ++i){
    cin >> temp;
    arr[i] = {i, temp};
  }
  sort(arr, arr+n, func);
  root.build(1, 0, n-1);
  int a, b, c;
  for(int i = 0 ; i < q; ++i){
    cin >> a >> b >> c;
    cout << root.query(1, 0, n-1, a-1, b-1, c) << "\n";
  }
}