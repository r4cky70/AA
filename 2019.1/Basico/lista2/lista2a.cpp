#include <bits/stdc++.h>
#define MAXS 200007

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;


int lista[MAXS];


int main(){

  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &lista[i]);
  }
  
  int cont = 0;
  int max = 0;
  
  for(int i = 0; i < n; i++){
    if(lista[i] == 1){
      cont++;
      if(cont > max) max = cont;
    }
    else{
      cont = 0;
    }
  }
  if(cont){
    int i = -1;
    while(i++ < n - 1){
      if(lista[i] == 0) break;
      cont++;
    }
  } if(cont > max) max = cont;
  printf("%d\n", max);
}