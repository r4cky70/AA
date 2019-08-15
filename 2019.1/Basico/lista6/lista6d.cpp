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
char mx[MAXS][MAXS];
queue <pii> ast, xis;
int d1[4] = {1, 0, 0, -1}, d2[4] = {0, -1, 1, 0};
bool vis[MAXS][MAXS];

int bfs(int a, int b){
  int cont = 0;
  if(mx[a][b] == '*') ast.push(mp(a, b));
  else {xis.push(mp(a, b)); cont++;}
  vis[a][b] = 1;
  while(!ast.empty() && !xis.empty()){
    while(!ast.empty()){
      a = ast.front().first; b = ast.front().second;
      ast.pop();
      for(int i = 0; i < 4; ++i){
        int x = a + d1[i], y = b + d2[i];
        if(!vis[x][y] && mx[x][y] == '*'){
          ast.push(mp(x, y));
          vis[x][y] = 1;
        }else if(!vis[x][y] && mx[x][y] == 'X'){
          xis.push(mp(x, y));
          cont++;
          while(!xis.empty()){
            int c = xis.front().first, d = xis.front().second;
            vis[c][d] = 1;
            xis.pop();
            for(int i2 = 0; i2 < 4; ++i2){
              int x1 = c + d1[i2], x2 = d + d2[i2];
              if(!vis[x1][x2] && mx[x1][x2] == 'X'){
                xis.push(mp(x1, x2));
              }else if(!vis[x1][x2] && mx[x1][x2] == '*'){
                ast.push(mp(x1, x2));
                vis[x1][x2] = 1;
              } 
            }
          }
        }
      }
    }
    while(!xis.empty()){
      a = xis.front().first; b = xis.front().second;
      xis.pop();
      vis[a][b] = 1;
      for(int i = 0; i < 4; ++i){
        int x = a + d1[i], y = b + d2[i];
        if(!vis[x][y] && mx[x][y] == 'X'){
          xis.push(mp(x, y));
        }else if(!vis[x][y] && mx[x][y] == '*'){
          ast.push(mp(x, y));
          vis[x][y] = 1;
        }
      }
    }
  }
  return cont;
}



int main(){
  inp; out;
  int caso = 0;
  while(cin >> n >> m, n != 0 || m != 0){
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= m; ++i){
      for(int j = 1; j <= n; ++j){
        cin >> mx[i][j];
      }
    }
    vi ans;
    for(int i = 1; i <= m; ++i){
      for(int j = 1; j <= n; ++j){
        if(mx[i][j] != '.' && !vis[i][j]){
          // cout << "abacaba" << endl;
          ans.pb(bfs(i, j));
        }
      }
    }
    sort(ans.begin(), ans.end());
    cout << "Throw " << ++caso << endl;
    for(int i = 0; i < ans.size() - 1; ++i) cout << ans[i] << ' ';
    cout << ans[ans.size() - 1] << "\n\n";
  }
}