#include <bits/stdc++.h>
#define MAXS 100007
#define INF 2147483647

#define mp(a, b) make_pair(a,b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define STREE int branch = no*2, mid = (l+r)/2
#define all(a) a.begin(), a.end()

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int arr[MAXS];
int n;

int j1, j2;

void solve(){
  j1 = 0, j2 = 0;
  int be = 0, en = n-1;
  int vez = 1;
  while(en - be > 1){
    if(vez&1){
      int co1 = arr[be] - arr[be+1];
      int co2 = arr[en] - arr[en-1];
      if(co2 > co1){
        j1 += arr[en];
        en--;
      }else{
        j1+= arr[be];
        ++be;
      }
    }else{
      int co1 = arr[be] - arr[be+1];
      int co2 = arr[en] - arr[en-1];
      if(co2 > co1){
        j2 += arr[en];
        en--;
      }else{
        j2+= arr[be];
        ++be;
      }
    }
    ++vez;
  }
  if(en-be == 1){
    j1+=(max(arr[en], arr[be]));
    j2+=(min(arr[en], arr[be]));
  }else{
    j2+=(max(arr[en], arr[be]));
    j1+=(min(arr[en], arr[be]));
  }
}




int main(){
  FASTIO;
  int t;
  cin >> t;
  while(t--){
    cin >> n;
    for(int i = 0; i < n; ++i){
      cin >> arr[i];
    }
    solve();
    if(n ==1) cout << arr[0] << "\n";
    else cout << j1 - j2 << "\n";
  }
}