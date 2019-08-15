#include <bits/stdc++.h>
#define INF 1234567890
#define MAXS 1007

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int t, n;
vector<pii > lista;

struct Sc{
  int peso;
  int q;
  int p;
  Sc(){peso = q = p = -1;}
  Sc(int a, int b, int c){
    peso = a;
    q=b;
    p=c;
  }
};
Sc dp[MAXS][MAXS];

Sc solve(int ind, int peso, int q, int p){
  if(dp[ind][peso].p != -1 && dp[ind][peso].peso != -1 && dp[ind][peso].q != -1) return dp[ind][peso];
  if(peso > 50) return Sc(0, 0, 0);
  if(ind == n) return Sc(peso, q, p);
  Sc s1 = solve(ind+1, peso+lista[ind].second, q+lista[ind].first, p+1), s2 = solve(ind+1, peso, q, p);
  Sc ans = (s1.q > s2.q ? s1 : s2);
  dp[ind][peso] = ans;
  return ans;
}


int main(){
  // INP; OUT;
  cin >> t;
  for(int i =0 ; i < t; ++i){
    memset(dp, -1, sizeof dp);
    cin >> n;
    int a, b;
    for(int j =0; j < n; ++j){
      cin >> a >> b;
      lista.pb(mp(a,b));
    }
    Sc ans = solve(0, 0, 0, 0);
    lista.clear();
    // for(int i = 0; i < n; ++i){
    //   for(int j = 0; j <=50; ++j){
    //     cout << "(" << i << ", " << dp[i][j].p << ", " << dp[i][j].peso << ", " << dp[i][j].q << "), ";
    //   }
    //   cout << "\n";
    // }
    cout << ans.q << " brinquedos\nPeso: " << ans.peso << " kg\nsobram(m) " << n-ans.p << " pacote(s)\n\n";
  }
}