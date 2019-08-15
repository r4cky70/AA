#include <bits/stdc++.h>
#define INF 1234567890
#define MAXS 200007

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;


int lista[2];
string conv(int a){
  string c;
  for(int i = 0; i < 8; ++i){
    c += a / (64 << i);
    a %= (64 << i);
  }
  return c;
}


int main(){
  for(int i = 0; i < 20; ++i){
    cout << conv(i) << endl;
  }
}