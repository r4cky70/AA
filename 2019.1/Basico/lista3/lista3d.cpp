#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector <int> vi;
typedef pair <int, int> pii;

#define mp make_pair

const int MAXS = 300007;

int n;
int lista[MAXS];
long long cont1, cont2, cont3;

int main(){
  cin >> n;
  
  for(int i = 0; i < n; i++){
    scanf("%d", &lista[i]);
    cont1 += lista[i];
  }
  for(int i = 0; i < n - 1; i++){
    scanf("%d", &lista[i]);
    cont2 += lista[i];
  }
  for(int i = 0; i < n - 2; i++){
    scanf("%d", &lista[i]);
    cont3 += lista[i];
  }
  printf("%lld\n%lld\n", cont1 - cont2, cont2 - cont3);
}