#include <bits/stdc++.h>
#define INF 1234567890
#define MAXS 45

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, t;
vector<pii> lista;

int solve(int t, int ind, int peso){
  int ans = peso;
  for(int i = ind; i < lista.size(); ++i){
    if(t - lista[i].second >= 0){
      int res = solve(t-lista[i].second, i+1, peso+lista[i].first);
      ans = max(res, ans);
    }
  }
  return ans;
}



int main(){
  int a, b;
  while(cin >> n, n != 0){
    cin >> t;
    for(int i= 0; i < n; ++i){
      cin >> a >> b;
      lista.pb(mp(a, b));
    }
    sort(lista.begin(), lista.end());
    cout << solve(t, 0, 0) << " min.\n";
    lista.clear();
  }
}