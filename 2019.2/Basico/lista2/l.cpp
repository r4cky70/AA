#include <bits/stdc++.h>
#define MAXS 200007
#define INF 1234567890

#define mp(a, b) make_pair(a,b)
#define pb push_back
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;

int arr[MAXS];

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> arr[i];
  }
  sort(arr, arr+n);
  int  p1 = 0, p2 = 0, ans = 0, atual  = 1;
  while(p2 < n){
    if(arr[p2] - arr[p1] <=5){
      ans = max(atual, ans);
      p2++;
      ++atual;
    }else{
      p1++;
      --atual;
    }
  }
  cout << ans << endl;
}