#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector <int> vi;
typedef pair <int, int> pii;

#define mp make_pair

const int MAXS = 200007;

int lista[MAXS];

int main(){
  int n, m, k, cont = 0, tcont = 0;
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < n; i++){
    scanf("%d", &lista[i]);
    if(lista[i] <= m) cont++;
    else{
      if(cont > k - 1) tcont += cont - k+1;
      cont = 0;
    }
  }
  if(cont > k - 1) tcont += cont - k+1;
  cout << tcont << endl;

}