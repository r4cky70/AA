#include <bits/stdc++.h>
#define MAXS 200007
#define make_pair(a, b) mp(a,b)
#define debug(a) cout << a << '\n'

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

int n;
int lista[100];
vi vect;

int main(){
  scanf("%d", &n);
  bool flag = false;
  for(int i = 0; i < n; ++i){
    scanf("%d", &lista[i]);
    if(lista[i] == 1) flag = true;
  }
  int cont = 0;
  for(int i = 0; i < n; ++i){
    if(lista[i] == 1){
      break;
    }
    ++cont;
  }
  for(int i = n - 1; i >= cont; --i){
    if(lista[i] == 1){
      break;
    }
    --n;
  }
  int kek = 1;
  for(int i = cont; i < n; ++i){
    if(lista[i] == 0) kek++;
    else {
      vect.push_back(kek);
      kek = 1;
    }
  }
  vect.push_back(kek);
  long long x = 1;
  for(int i = 0; i < vect.size(); ++i){
    x *= vect[i];
  }
  if(!flag) printf("0\n"); 
  else printf("%lld\n", x);
}