#include <bits/stdc++.h>
#define MAXS 200007

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

int n, m;
int arraya[MAXS], arrayb[MAXS];






int main(){
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n;i++){
    scanf("%d", &arraya[i]);
  }
  for(int i  =0 ; i < m; i++){
    scanf("%d", &arrayb[i]);
  }
  sort(arraya, arraya + n);
  for(int i = 0; i < m; i++){
    printf("%ld ", upper_bound(arraya, arraya + n, arrayb[i]) - arraya);
  }

}