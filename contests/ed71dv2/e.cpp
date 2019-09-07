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

int main(){
  string ans = "00000000000000";
  int a;
  cout << "? ";
  for(int i = 1; i < 101; ++i) cout << i << " ";
  cout << endl;
  cin >> a;

  {
    for(int i = 0; i < 7; ++i){
      ans[i] = (a/(1<<(13-i)))+'0';
      a%=(1<<(13-i));
    }
  }


  cout << "? ";
  for(int i = 1; i < 101; ++i) cout << (i << 7) << " ";
  cout << endl;
  cin >> a;

  {
    a%= (1<<7);
    for(int i = 0; i < 7; ++i){
      ans[7+i] = (a/(1<<6-i))+'0';
      a%=(1<<6-i);
    }
  }
  // cout << ans << endl;
  int res = 0;
  for(int i = 0; i < 14; ++i){
    res += (ans[i]-'0')*(1<<(13-i));
  }
  cout << "! " << res << endl;
}