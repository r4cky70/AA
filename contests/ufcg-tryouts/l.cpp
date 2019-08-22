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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, arr[MAXS];

int main(){
	
	cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> arr[i];
  }
  int temp = arr[0];
  for(int i = 1; i < n; ++i){
    temp = __gcd(temp, arr[i]);
  }
  if(temp != arr[0]){
    cout << -1;
    return 0;
  }
  cout << 2*n-1 << "\n";
  for(int i = 0; i < n; ++i){
    cout << arr[i] << " ";
    if(i <n-1) cout << arr[0] << " ";
  }
}