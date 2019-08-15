#include <bits/stdc++.h>
#define MAXS 507

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  if(n < m){
    int temp;
    temp = n;
    n = m;
    m = temp;
  }
  if(m % 2 == 0){
    printf("Malvika");
  } else {
    printf("Akshat");
  }
}