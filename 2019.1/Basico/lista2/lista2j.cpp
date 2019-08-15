#include <bits/stdc++.h>
#define MAXS 200007

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

int lista[MAXS], mods[100];


int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++){
    scanf("%d", &lista[i]);
    mods[lista[i] % m]++;
  }
  int cont = 0;
  
  cont += (mods[0] / 2) * 2;
  for(int i = 1; i <= m/2; i++){
    if(i != m - i){
      cont += min(mods[i], mods[m - i]) * 2;
    }    
    else cont += mods[i];
  }
  printf("%d\n", cont);

}