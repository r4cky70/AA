#include <bits/stdc++.h>
#define INF 2034567890
#define MAXS 200007

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define inp freopen("input.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
  int n;
  cin >> n;
  int ans = 0;
  for(int i = 1; i <= n; ++i){
    if(n % i == 0) ++ans;
  }
  cout << ans << endl;
}