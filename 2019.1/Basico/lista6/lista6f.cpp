#include <bits/stdc++.h>
#define MAXS 200007

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define BZ freopen("input.txt", "r", stdin)
#define BX freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;



int idk(int x){
  int cont= 0;
  while(x < m){
    x *= 2;
    cont++;
  }
  if(x == m) return cont;
  for(int i = cont; i >= 0; --i){
    while(x - pow(2, i) >= m){
      x -= pow(2, i);
      cont++;
      
    }
  }
  return cont;

}



int main(){
  cin >> n >> m;
  cout << idk(n);
}