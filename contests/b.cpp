#include <bits/stdc++.h>
#define INF 2034567890
#define MAXS 10007

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vector<pair<int, int>> sla;
char mx[MAXS][MAXS];
int solv[MAXS][MAXS];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(int i = 0; i < n;++i){
    for(int j = 0; j < n; ++j){
      cin >> mx[i][j];
      if(mx[i][j] == '0'){
        sla.pb(mp(i, j));
      }
    }
  }
  for(int i = 0; i < n;++i){
    for(int j = 0; j < n; ++j){
      if(mx[i][j] == '0'){
        solv[i][j] = 0;
      }
      else{
        int minimo = 9;
        for(int k = 0; k < sla.size(); ++k){
          int temp = abs(i - sla[k].first) + abs(j - sla[k].second);
          minimo = min(temp, minimo);
        }
        solv[i][j] = minimo;
      }
    }
  }
  for(int i = 0; i < n;++i){
    for(int j = 0; j < n; ++j){
      cout << solv[i][j];
    }
    cout << "\n";
  }
}