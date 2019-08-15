#include <bits/stdc++.h>
#define MAXS 1007
#define make_pair(a, b) mp(a,b)
#define debug(a) cout << a << '\n'

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

int n;
bitset<MAXS> cri;
vi prims;
vi sol;

void sieve(){
  cri.set();
  cri[0] = cri[1] = 0;
  for(int i = 2; i < MAXS; i++){
    if(cri[i]){
      prims.push_back(i);
      for(int j = i + i; j < MAXS; j += i){
        cri[j] = 0;
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  sieve();
  scanf("%d", &n);
  for(int i = 0; i < prims.size(); i++){
    if(prims[i] > n) break;
    sol.push_back(prims[i]);
    for(int j = 2; pow(prims[i], j) <= n; j++){
      sol.push_back(pow(prims[i], j));
    }
  }
  debug(sol.size());
  for(int i = 0; i < sol.size(); i++){
    cout << sol[i] << " ";
  }
}