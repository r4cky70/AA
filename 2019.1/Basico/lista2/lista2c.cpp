#include <bits/stdc++.h>
#define MAXS 107

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

int n, k, x, lista[MAXS];

bool inside(int t){
  return t > -1 && t < n ? 1 : 0;
}


int simul(int p1, int p2){
  int cor = lista[p1];
  int rep = 1;
  int max = 0;
  while(true){
    if(lista[p1] == lista[p2]) cor = lista[p1];
    for(p1; inside(p1); p1--){
      if(lista[p1] == cor) rep++;
      else break;
    }
    for(p2; inside(p2); p2++){
      if(lista[p2] == cor) rep++;
      else break;
    }
    if(rep >= 3) max += rep;
    else break;
    rep = 0;
  }
  return max - 1;
}





int main(){
  scanf("%d %d %d", &n, &k, &x);
  for(int i = 0; i < n; i++){
    scanf("%d", &lista[i]);
  }
  int max = 0;
  for(int i = 0; i < n - 2; i++){
    if(lista[i] == x && lista[i + 1] == x){
      int kek = simul(i, i+1);
      if(kek > max) max = kek;
    }
  }
  printf("%d\n", max);

}