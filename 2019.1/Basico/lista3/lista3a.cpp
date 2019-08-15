#include <bits/stdc++.h>
#define MAXS 2007
#define make_pair(a, b) mp(a,b)

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

int n;
int lista[MAXS];
stack <int> fila;

int main(){ 
  while(scanf("%d", &n), n != 0){
    for(int i = 0; i < n; i++){
      scanf("%d", &lista[i]);
    }
    int cont = 1;
    int in = 0;
    while(in < n){
      while(!fila.empty()){
        if(fila.top() == cont){
          fila.pop();
          cont++;
        } else break;
      }
      fila.push(lista[in]);
      in++;
    }
    while(!fila.empty()){
      if(fila.top() == cont){
        fila.pop();
        cont++;
      } else break;
    }
    if(fila.empty()) printf("yes\n");
    else printf("no\n");
    while(!fila.empty()) fila.pop();
  }
}