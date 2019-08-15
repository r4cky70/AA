#include <bits/stdc++.h>
#define MAXS 1000000007
#define make_pair(a, b) mp(a,b)
#define debug(a) cout << a << '\n'

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

ll n;

int main(){
  cin >> n;
  ll cont = 0;
  for(ll i = 1; i <= n; ++i){
    cont += 1ll << i;
  }
  cout << cont << endl;
}