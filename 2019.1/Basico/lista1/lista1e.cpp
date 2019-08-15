#include <bits/stdc++.h>
#define MAXS 507

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

ll n1, n2, k;


int main(){
  scanf("%lld %lld %lld", &n1, &n2, &k);
  int x = k, cont = 0;
  if(1 >= n1 && 1 <= n2) printf("1 ");
  while(x <= n2){
    if(x > n1){
      printf("%d ", x);
      cont++;
    }
    x *= k;
  } if(cont == 0) printf("-1");

}