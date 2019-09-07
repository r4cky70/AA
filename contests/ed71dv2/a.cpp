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

int main(){
  cin >> n;
  int a, b, c;
  int x, y;
  for(int i = 0; i < n; ++i){
    int ans = 0;
    cin >> a >> b >> c;
    a/=2;
    cin >> x >> y;
    if(x > y){
      ans += min(a, b)*x;
      a-=min(a, b);
      ans+= min(a, c) * y;
    }else {
      ans += min(a, c)*y;
      a-=min(a, c);
      ans+= min(a, b) * x;
    }
    cout << ans << "\n";
  }
}