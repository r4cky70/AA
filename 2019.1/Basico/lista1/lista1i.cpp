#include <bits/stdc++.h>
#define MAXS 100007

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

int main(){
  int n, m, lista[MAXS], x, y, z;

  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++){
    scanf("%d", &lista[i]);
  }
  int acumul = 0;

  for(int i = 0; i < m; i++){
    scanf("%d %d", &x, &y);
    if(x == 1){
      scanf("%d", &z);
      if(acumul != 0){
        for(int j = 0; j < n; j++){
          lista[j] += acumul;
        }
        acumul = 0;
      }
      lista[y - 1] = z;
    }
    else if (x == 2){
      acumul += y;  
    }else{
      if(acumul != 0){
        for(int j = 0; j < n; j++){
          lista[j] += acumul;
        }
        acumul = 0;
      }
      printf("%d\n", lista[y - 1]);
    }
  }

}