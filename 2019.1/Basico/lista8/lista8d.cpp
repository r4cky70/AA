#include <bits/stdc++.h>
#define INF 1234567891
#define MAXS 1007

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define BZ freopen("input.txt", "r", stdin)
#define BX freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, k;
int lista[MAXS];

int br(int o, int b){
  int cont = 0;
  for(int i = 1 << n; i > 0; i = i / 2){
    if((o&i) != (b&i)) ++cont;
  }
  
  return cont;
}





int main(){
  cin >> n >> m >> k;
  for(int i = 0; i < m+1; ++i){
    cin >> lista[i];
  }
  int ans = 0;
  int j;
  for(int i = 0; i < m; ++i){
    if(br(lista[i], lista[m]) <= k) ++ans;
  }
  cout << ans;

}