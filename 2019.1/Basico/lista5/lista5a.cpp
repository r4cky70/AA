#include <bits/stdc++.h>
#define MAXS 1000000007
#define make_pair(a, b) mp(a,b)
#define debug(a) cout << a << '\n'

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

ll MOD = 1000000007;

ll mult(ll a, ll b){
  return ((a%MOD) * (b%MOD))%MOD;
}

ll exp(ll a, ll b){
  if(b == 0) return 1;
  if(b == 1) return a;
  if(b&1){
    return mult(a ,exp(a, b - 1));
  } else{
    ll x = exp(a, b / 2);
    return mult(x, x);

  } 
}

ll n, a, b;

int main(){
#ifdef BZ
  freopen("input.txt", "r", stdin);
#endif
  scanf("%lld", &n);
  for(int i = 0; i < n; i++){
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", exp(a, b));
  }
}