#include <bits/stdc++.h>
#define MAXS 500007
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

int n;
string s;



int main(){
  int t;
  cin >> t;
  while(t--){
    cin >> n;
    int a = 0, b = 0, c = 0;
    for(int i = 0; i < n; ++i){
      cin >> s;
      if(s[0] == 'b') a++;
      else if(s[0]=='l')b++;
      else c++;
    }
    cout << min(min(a/2, b), c) << endl;
  }
}