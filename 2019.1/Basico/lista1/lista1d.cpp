#include <bits/stdc++.h>
#define MAXS 507

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

int main(){
  int n;
  scanf("%d", &n);
  if(n % 5 != 0){
    printf("%d", n / 5 + 1);
  }
  else printf("%d", n / 5);
}