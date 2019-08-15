#include <bits/stdc++.h>
#define MAXS 57

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define inp freopen("input.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
int mx1[MAXS][MAXS], mx2[MAXS][MAXS];

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      cin >> mx1[i][j];
    }
  }
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      cin >> mx2[i][j];
    }
  }
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(mx1[i][j] > mx2[i][j]){
        swap(mx1[i][j], mx2[i][j]);
      }
    }
  }
  
  bool flag = true;

  for(int i = 0; i < n; ++i){
    for(int j = 0 ; j < m - 1; ++j){
      if(mx1[i][j] >= mx1[i][j+1]){
        flag = false;
        break;
      }
    }
  }
  for(int i = 0; i < n; ++i){
    for(int j = 0 ; j < m - 1; ++j){
      if(mx2[i][j] >= mx2[i][j+1]){
        flag = false;
        break;
      }
    }
  }
  for(int i = 0; i < m; ++i){
    for(int j = 0 ; j < n - 1; ++j){
      if(mx1[j][i] >= mx1[j+1][i]){
        flag = false;
        break;
      }
    }
  }
  for(int i = 0; i < m; ++i){
    for(int j = 0 ; j < n - 1; ++j){
      if(mx2[j][i] >= mx2[j+1][i]){
        flag = false; 
        break;
      }
    }
  }
  cout << (flag ? "Possible" : "Impossible");
}