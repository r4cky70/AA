#include <bits/stdc++.h>
#define MAXS 200007

using namespace std;

typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

int main(){
  int n, m;
  int lista1[9], lista2[9];

  scanf("%d %d", &n, &m);

  for(int i = 0; i < n; i++){
    scanf("%d", &lista1[i]);
  }
  for(int i = 0; i < m; i++){
    scanf("%d", &lista2[i]);
  }
  sort(lista1, lista1 + n); sort(lista2, lista2 + m);

  bool flag = false;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(lista1[i] == lista2[j]) {
        flag = true;
        break;
      }
    }
    if(flag) {
      printf("%d\n", lista1[i]);
      break;
    }
  }
  if(!flag){
    int lista[2] = {lista1[0], lista2[0]};
    sort(lista, lista + 2);
    printf("%d%d\n", lista[0], lista[1]);
  }

}