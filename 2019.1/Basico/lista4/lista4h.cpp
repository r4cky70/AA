#include <bits/stdc++.h>
#define MAXS 200007
#define make_pair(a, b) mp(a,b)
#define debug(a) cout << a << '\n';

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

int n;
int lista[MAXS];
int gcds[MAXS], mcms[MAXS];

int gcd(int a, int b){
  if(a == 0) return b;
  if(b == 0) return a;
  return gcd(b, a % b);
}

int mcm(int a, int b){
  return a * (b / gcd(a, b));
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> lista[i];
  }
  // for(int i = 0; i < n-1; i++){
  //   mcms[i] = mcm(lista[i], lista[i + 1]);
  //   gcds[i] = gcd(lista[i], lista[i+1]);
  // }
  // for(int i =0; i < n - 1; i++){
  //   cout << gcds[i] << " " << mcms[i] << '\n';
  // }
  cout << mcm(lista[1], lista[2]) << '\n';
}