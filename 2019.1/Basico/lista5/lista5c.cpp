#include <bits/stdc++.h>
#define MAXS 200007
#define make_pair(a, b) mp(a,b)
#define debug(a) cout << a << '\n'

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

int n, m;
int MOD = 1000000007;
string lista[101];
set <char> conju;

int mult(ll a, ll b){
  return ((a % MOD) * (b % MOD)) % MOD;
}



int main(){
  scanf("%d %d", &n, &m);
  int cont = 1;
  for(int i = 0; i < n; ++i){
    cin >> lista[i];
  }
  for(int i = 0; i < m; ++i){
    conju.clear();
    for(int j = 0; j < n; ++j){
      conju.insert(lista[j][i]);
    }
    cont = mult((long long)conju.size(), cont);
  }
  printf("%d\n", cont);
}