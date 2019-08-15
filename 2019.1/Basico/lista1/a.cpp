#include <bits/stdc++.h>
#define MAXS 507

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

int main(){
  int n, lista[MAXS];
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &lista[i]);
  }
  sort(lista, lista + n);
  int cont = 0, var = 0;
  for(int i = 0; i < n; i++){
    if(lista[i] != var){
      cont++; var = lista[i];
    }
  }
  printf("%d\n", cont);
}