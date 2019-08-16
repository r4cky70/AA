#include <bits/stdc++.h>
#define MAXS 100007
#define INF 2147483647

#define make_pair(a, b) mp(a,b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define STREE int bch = no*2, mid = (l+r)/2
#define ALL(a) a.begin(), a.end()

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main(){
  vi idk(10);
  for(int i = 0; i < 10; ++i){
    idk[i] = i;
  }
  shuffle(idk.begin(), idk.end(), rng);
  uniform_int_distribution<ll> t;
  cout << t << endl << endl;
  cout << INF << endl;
  for(int i =0 ;i < 10; ++i){
    cout << idk[i] << endl;
  }
  
}