#include <bits/stdc++.h>
#define MAXS 1007

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

int main(){
  int n;
  int lista[MAXS];
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &lista[i]);
  }
  sort(lista, lista + n);
  for(int i = 0; i < n; i++){
    printf("%d ", lista[i]);
  }
}