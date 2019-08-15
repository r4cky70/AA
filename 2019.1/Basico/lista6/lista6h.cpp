#include <bits/stdc++.h>
#define MAXS 1007

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define BZ freopen("input.txt", "r", stdin)
#define BX freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int mx[MAXS][MAXS];
bool vis[MAXS][MAXS];

int n, a, b;

void dfs(int a, int b){
  vis[a][b] = 1;
  for(int i = 1; i <= 1000; ++i){
    if(mx[i][b] == 2 && vis[i][b] == 0){
      dfs(i, b);
    }
  }
  for(int j = 1; j <= 1000; ++j){
    if(mx[a][j] == 2 && vis[a][j] == 0){
      dfs(a, j);
    }
  }
}


int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> a >> b;
    mx[a][b] = 2;
  }
  int vont = -1;
  for(int i = 1; i <= 1000; ++i){
    for(int j = 1; j <= 1000; ++j){
      if(mx[i][j] == 2 && vis[i][j] == 0){
        dfs(i, j);
        vont++;
      }
    }
  }
  cout << vont;
}