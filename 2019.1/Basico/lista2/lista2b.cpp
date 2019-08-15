#include <bits/stdc++.h>
#define MAXS 200007

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

queue <ii> fila;
int n, m;



int main(){
  scanf("%d %d", &n, &m);
  fila.push(make_pair(n, 0));  
  while(!fila.empty()){
    if(fila.front().first == m) break;
    if(fila.front().first < m){
      fila.push(make_pair(fila.front().first * 2, fila.front().second + 1));
      fila.push(make_pair(fila.front().first * 3, fila.front().second + 1));
    }
    fila.pop();
  }
  printf("%d\n", !fila.empty() ? fila.front().second : -1);


}