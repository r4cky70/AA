#include <bits/stdc++.h>
#define MAXS 1000000007

#define make_pair(a, b) mp(a,b)
#define pb push_back
#define BZ freopen("input.txt", "r", stdin)

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;

int n;
int d1[3000], d2[3000];
int a, b;

long long comb(int x){
  ll ans = 0;
  for(int i = 1; i < x; ++i) ans += i;
  return ans;
}


int main(){
  
  // memset(d1, 0, sizeof d1);
  // memset(d2, 0, sizeof d2);
  cin >> n;
  
  for(int i = 0; i < n; ++i){
    cin >> a >> b;
    d1[1000  + (a - b)]++;
    d2[a + b]++;
  }
  ll ans = 0;
  for(int i = 0; i <= 3000; ++i){
    if(d1[i] > 1) ans += comb(d1[i]);
    if(d2[i] > 1) ans += comb(d2[i]);
  }
  cout << ans << endl;
}