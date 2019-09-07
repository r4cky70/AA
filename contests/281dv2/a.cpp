#include <bits/stdc++.h>
#define INF 2034567890
#define MAXS 20007

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string s;


int main(){
  cin >> s;
  int ans = 0;
  for(int i = 0; i <= s.size(); ++i){
    if(s[i] == '1') ++ans;
  }
  if(ans == 0) cout << ans;
  else if(ans == 1) cout << (s.size()-1)/2;
  else cout << ((s.size()-1)+1)/2;
}