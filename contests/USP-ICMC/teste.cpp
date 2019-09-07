#include <bits/stdc++.h>
#define MAXS 1000000007
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


bitset <MAXS> cri;
vi prims;

void sieve(){
  for(int i = 0; i < MAXS; i++){
    cri[i] = true;
  }

  cri[0] = cri[1] = false;
  for(int i = 2; i < MAXS; ++i){
    if(cri[i]){
      for(int j = i*2; j < MAXS; j+=i){
        cri[j] = false;
      }
      prims.pb(i);
    }
  }
}

int main(){
  
  sieve();
  cout << prims.size() << endl;
}