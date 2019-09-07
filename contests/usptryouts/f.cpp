#include <bits/stdc++.h>
#define MAXS 1007
#define INF 2147483647

#define mp(a, b) make_pair(a,b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define STREE int bch = no*2, mid = (l+r)/2
#define all(a) a.begin(), a.end()

using namespace std;
typedef long long int ll;
typedef vector < int > vi;
typedef pair < int, int > pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool check(ll n,ll k){

  while(n>k && n%k==0){
    n/=k;
  }

  if(n == k) return true;
  return false;
}

ll divisor(ll k){
  
  ll lim = (ll)sqrt(k);
  if(check(k,2)) return 2;
  for(ll i = 3;i<=lim;++i){
    if(k%i == 0){
      if(check(k,i)) return i;
    }
  }

  return k;

}

int main(){

  ll a,b;
  cin>>a>>b;

  ll gc = __gcd(a,b);
  a/=gc;
  b/=gc;

  cout<<divisor(b)<<endl;

}
