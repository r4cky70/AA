#include <bits/stdc++.h>
#define MAXS 1000007
#define make_pair(a, b) mp(a,b)
#define debug(a) cout << a << '\n';

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

long long n;
vector <ll> pot;

void take_div(long long k){
  for(long long i = 1; i <= sqrt(k); i++){
    if(k % i == 0){
      pot.push_back(i);
      pot.push_back(k / i);
    } 
  }
}




int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  take_div(n);
  sort(pot.begin(), pot.end());
  for(ll i = pot.size() - 1; i > -1; i--){
    bool flag = false;
    for(ll j = 2; j <= sqrt(pot[i]); j++){
      if(pot[i] % (j * j) == 0) {
        flag = 1;
        break;
      }
    }
    if(!flag){
      cout << pot[i] << '\n';
      break;
    }
  }
  
}
