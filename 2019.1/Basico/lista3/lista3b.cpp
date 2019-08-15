#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector <int> vi;
typedef pair <int, int> pi;

#define mp make_pair

const int MAXS = 200007;


pi lista[MAXS];
int t, x, y;
int a = -1, b = -1;

int main(){
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    scanf("%d %d", &x, &y);
    lista[i] = mp(x, y);
  }
  sort(lista, lista + t);
  bool flag = false;
  for(int i = 0; i < t; i++){
    if(lista[i].first > a && lista[i].second > a){
      a = lista[i].second;
    }
    else if(lista[i].first > b && lista[i]. second > b) b = lista[i].second;
    else{
      flag = true;
      break;
    }
  }
  printf(flag ? "NO\n":"YES\n");
}