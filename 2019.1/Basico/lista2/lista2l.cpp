#include <bits/stdc++.h>
#define make_pair(a, b) mp(a, b)
#define MAXS 100007

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

int main(){
  int n, lista[MAXS];
  long long sum = 0;
  scanf("%d", &n);
  for(int i=0; i < n; i++){
    scanf("%d", &lista[i]);
    sum += lista[i];
  }
  long long sumb = 0, cont = 0;
  for(int i = 0; i < n - 1; i++){
    sumb += lista[i];
    sum -= lista[i];
    if(sumb == sum){
      cont++;
    }
  }
  printf("%lld\n", cont);
}