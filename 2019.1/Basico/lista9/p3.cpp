#include <bits/stdc++.h>
#define INF 1234567890
#define MAXS 100007

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, a, lista[MAXS];
long long comp[MAXS];
ll dp[MAXS];


ll solve(int ind){
  if(ind > 100000) return 0;
  if(dp[ind] != -1) return dp[ind];
  ll ans = max(comp[ind]+solve(ind+2), solve(ind +1));
  return dp[ind] = ans;
}

int main(){
  cin >> n;
  for(int i = 0; i < n ; ++i){
    cin >> a;
    lista[a]++;
  }
  for(int i = 1; i < MAXS; ++i){
    comp[i] = 1LL * i * lista[i];
  }
  memset(dp, -1, sizeof dp);
  cout << solve(1);
}