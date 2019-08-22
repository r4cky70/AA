#include <bits/stdc++.h>
#define MAXS 100007
#define INF 2147483647

#define mp(a, b) make_pair(a,b)
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

int a, b;



int main(){
  int n = 1000;
  int cont = 0;
  string s;
  for(int i = 0; i <= 1000; ++i){
    s = to_string(n);
    ++n;
    int temp =0;
    for(int j = 0; j < s.size(); ++j){
      if(s[j] != '0')++temp;
    }
    if(temp <= 3) ++cont;
  }
  cout << n << endl;
  cout << cont << endl;
}