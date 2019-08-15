#include <bits/stdc++.h>
#define MAXS 1000000007
#define make_pair(a, b) mp(a,b)

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

ll n, m;

ll comb(ll a){
  return a * (a - 1) / 2;
}



int main(){
  cin >> n >> m;
  ll ans = 0;
  ll max = comb(n - (m - 1));
  ll min = (m - (n % m)) * comb(n / m);
  min += (n % m) * comb(n / m + 1);
  
  cout << min << ' ' << max;

}