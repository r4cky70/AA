#include <bits/stdc++.h>
#define MAXS 200007
#define make_pair(a, b) mp(a,b)
#define debug(a) cout << a << '\n'

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

int n, a, b;
int lista[MAXS];

int main(){
  scanf("%d", &n);
  int min = (int)1e9, max = 0;
  int cont1 = 0, cont2 = 0;
  for(int i = 0; i < n; ++i){
    scanf("%d", &lista[i]);
    if(lista[i] > max){
      max = lista[i];
      cont2 = 0;
    }
    if(lista[i] == max) cont2++;
    if(lista[i] < min){
      min = lista[i];
      cont1 = 0;
    }
    if(lista[i] == min) cont1++;
  }
  if(max == min) printf("%d %lld\n", max - min, (long long)(n - 1) * n / 2);
  else printf("%d %lld\n", max - min, (long long)cont1 * cont2);

}