#include <bits/stdc++.h>
#define MAXS 1000007
#define make_pair(a, b) mp(a,b)
#define debug(a) cout << a << '\n'

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

long long n, x;
bitset <MAXS> cri;
vector <int> prims;

void sieve(){
  cri.set();
  for(int i = 2; i < MAXS; i++){
    if(cri[i]){
      prims.push_back(i);
      for(int j = i + i; j < MAXS; j += i){
        cri[i] = false;
      }
    }
  }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x;
    if(x < 1000000){
      cout << (cri[x] ? "YES\n" : "NO\n");
    } else {
      bool flag = 1;
      long long q = sqrt(x);
      for(int i = 0; i < prims.size(); i++){
        if(prims[i] > q) break;
        if(x % prims[i] == 0){
          flag = false;
          break;
        }
      }
      cout << (flag ? "YES\n" : "NO\n");
    }
  }

}