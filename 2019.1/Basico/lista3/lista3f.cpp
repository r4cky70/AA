#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector <int> vi;
typedef pair <int, int> pii;

#define mp make_pair

const int MAXS = 100007;

int n, m;
int lista[MAXS];
int yo[MAXS];
set <int> fon;

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    scanf("%d", &lista[i]);
  }
  int cont = 0; int ai;
  for(int i = n - 1; i > -1; i--){
    // int ai = fon.size();
    if(fon.find(lista[i]) == fon.end()) cont++;
    yo[i] = cont;
    fon.insert(lista[i]);
  }
  for(int i = 0; i < m; ++i){
    scanf("%d", &cont);
    printf("%d\n", yo[cont - 1]);
  }
}