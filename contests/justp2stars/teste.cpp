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


string bina(ll a){
  string s;
  for(int i = 0; i < 32; ++i){
    s+=a/(1<<31-i)+'0';
    a%=(1<<31-i);
  }
  return s;
}
ll check2(ll a){
  ll ans = 0;
  while(a > 1){
    if(a&1)++ans;
    a=(a>>1);
    if(a==0) break;
    ++ans;
    cout << a << " " << ans <<  endl;
  }
  return ans;
}

int main(){
  int n;
  cin >> n;
  cout << bina(n) << endl;
  cout << check2(n) << endl;
}