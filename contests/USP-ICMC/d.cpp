#include <bits/stdc++.h>
#define MAXS 100007
#define INF 2147483647

#define mp(a, b) make_pair(a,b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define STREE int bch = no*2, mid = (l+r)/2
#define all(a) a.begin(), a.end()

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string s, c;

int main(){
  cin >> s;
  cin >> c;
  int j = 0;
  int p1 = 0; int p2 = 0;
  while(p1 < s.size()){
    if(p2 == c.size()) break;
    if(s[p1] == c[p2]){
      ++p2;
    }
    ++p1;
  }
  if(p2 == c.size())cout << "YES\n";
  else cout << "NO\n";

}
