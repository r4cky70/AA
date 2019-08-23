#include <bits/stdc++.h>
#define MAXS 500007
#define INF 2147483647

#define mp(a, b) make_pair(a,b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define STREE int bch = no*2, mid = (l+r)/2
#define ALL(a) a.begin(), a.end()

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
int arr[MAXS], ans[MAXS];;
int spt[MAXS][25];

void build(){
  for(int i = 0; i < n; ++i) spt[i][0] = arr[i];
  for(int i = 1; (1<<i)<=n; ++i){
    for(int j = 0; j+(1<<i)<=n; ++j){
      spt[j][i] = min(spt[j][i-1], spt[j+(1<<i-1)][i-1]);
    }
  }
}
ll query(int l, int r){
  if(l > r) swap(l, r);
  int lg = __builtin_clz(1) - __builtin_clz(r-l+1);
  return min(spt[l][lg], spt[r-(1<<lg)+1][lg]);
}

int busca(int l, int r, int v){
  int ans = 0;
  while(l < r-1){
    int mid = (l+r)/2;
    if(query(l, mid) >= v){
      ans = mid;
      l = mid+1;
    }else{
      r = mid;
    }
  }
  if(arr[l] >= v && arr[r] >= v) ans = r;
  else if(arr[l] >= v) ans = l;
  return ans;
}
int busca2(int l, int r, int v){
  int ans = 0;
  while(l < r-1){
    int mid = (l+r)/2;
    if(query(mid+1, r) >= v){
      ans = mid+1;
      r = mid;
    }else{
      l = mid+1;
    }
  }
  if(arr[r]>=v && arr[l]>= v) ans = l;
  else if(arr[r]>=v) ans= r;
  return ans;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> arr[i];
  }
  build();
  for(int i = 0; i < n; ++i){
    int temp = 0;
    int a = busca(i, n-1, arr[i]);
    int b = busca2(0, i, arr[i]);
    temp += i - b;
    temp += a - i+1;
    ans[temp] = max(arr[i], ans[temp]);
  }
  int idk = ans[n];
  for(int i = n-1; i > 0; --i){
    if(idk > ans[i]) ans[i] = idk;
    idk = ans[i];
  }
  for(int i = 1; i <= n; ++i){
    cout << ans[i] << " ";
  }cout << endl;
}