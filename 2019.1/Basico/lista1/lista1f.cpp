#include <bits/stdc++.h>
#define MAXS 200007

using namespace std;

typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

int lista[MAXS];
int min, max;

int main(){
  int n;
  scanf("%d", &n);
  
  
  
  for(int i = 0; i < n; i++){
    scanf("%d", &lista[i]);
  }

  printf("%d %d\n", abs(lista[0] - lista[1]), abs(lista[0] - lista[n - 1]));

  int min = lista[0], max = lista[n - 1];
  
  for(int i = 1; i < n - 1; i++){
    if(abs(lista[i] - lista[i + 1]) < abs(lista[i] - lista[i - 1])) printf("%d ", abs(lista[i] - lista[i + 1]));
    else printf("%d ", abs(lista[i] - lista[i - 1]));

    if(abs(lista[i] - min) > abs(lista[i] - max)) printf("%d\n", abs(lista[i] - min));
    else printf("%d\n", abs(lista[i] - max));

  }

  printf("%d %d\n", abs(lista[n - 1] - lista[n - 2]), abs(lista[n - 1] - lista[0]));

  
}