#include <bits/stdc++.h>
#define MAXS 5000007
#define make_pair(a, b) mp(a,b)
#define debug(a) cout << a << '\n';

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

int n, k, t;
bitset<MAXS>cri;
vector <int> prims;
int fatores[MAXS];

void sieve(){
  cri.set();
  cri[1] = cri[0] = 0;
  for(int i = 2; i < MAXS; i++){
    if(cri[i]){
      prims.push_back(i);
      for(int j = i + i; j < MAXS; j+=i){
        cri[j] = 0;
      }
    }
  }
}
int main(){
  sieve();
  //for(int i = 0; i < 10; i++) cout << prims[i] << " ";
  //cout << endl;
  for(int i = 2; i < MAXS; i++){
    int ind = 0;
    int val = i;
    while(val > 1 && ind < prims.size() && prims[ind]*prims[ind]<=val){
      while((val%prims[ind]) == 0){
        val /= prims[ind];
        fatores[i]++;
      } 
      ind++;
      
    }
    if(val != 1) fatores[i]++;
  }
  //printf("asdh\n");
  for(int i = 1; i < MAXS; i++){
    fatores[i] += fatores[i - 1];
  }
  scanf("%d", &k);
  for(int i = 0; i < k; i++){
    scanf("%d %d", &n, &t);
    printf("%d\n", fatores[n] - fatores[t]);

  }

}
