#include <bits/stdc++.h>
#define MAXS 234567

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define inp freopen("input.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
const int MOD = (int)10e9 + 7;

ll mul(ll a, ll b){
  return (a % MOD * b % MOD) % MOD;
}

long long fastExp(long long a, long long b){
  if(b == 0) return 1;
  if(b%2 == 0){
    long long x = fastExp(a, b/2);
    return mul(x, x);
  }
  return mul(fastExp(a, b - 1), a);
}

int main(){
  cin >> n >> m;
  cout << fastExp(n, m) << endl;
}