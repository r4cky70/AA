#include <bits/stdc++.h>
#define MAXS 57

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define BZ freopen("input.txt", "r", stdin)
#define BX freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

char mx[MAXS][MAXS];
int vis[MAXS][MAXS];
int a1, a2, b1, b2, n;
queue <pair<int, int>> fila;

int d1[4] = {-1, 0, 0, 1}, d2[4] = {0, -1, 1, 0};

vector <pair<int, int>> v1, v2;

bool inside(int a, int b){
  return a > 0 && a <= n && b > 0 && b <= n;
}


bool bfs(int a, int b){
  fila.push(mp(a, b));
  while(!fila.empty()){
    a = fila.front().first; b = fila.front().second;
    vis[a][b] = 1;
    v1.pb(mp(a, b));
    fila.pop();
    for(int i = 0; i < 4; ++i){
      int x = a + d1[i], y = b + d2[i];
      cout << x << " " << y << endl;
      if(inside(x, y) && mx[x][y] == 'c'){
        return true;
      }else if(inside(x, y) && mx[x][y] == '0' && vis[x][y] == 0){
        fila.push(mp(x, y));
      }
    }
  }
  return false;
}

void bfs2(int a, int b){
  fila.push(mp(a, b));
  while(!fila.empty()){
    a = fila.front().first; b = fila.front().second;
    vis[a][b] = 2;
    v2.pb(mp(a, b));
    fila.pop();
    for(int i = 0; i < 4; ++i){
      int x = a + d1[i], y = b + d2[i];
      if(inside(x, y) && mx[x][y] == '0' && vis[x][y] < 1){
        fila.push(mp(x, y));
      }
    }
    // cout << 'a'   << " ";
  }
}


int main(){
  // BZ;BX;
  cin >> n;
  cin >> a1 >> b1;
  cin >> a2 >> b2;
  vis[a2][b2] = 2;
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      cin >> mx[i][j];
    }
  }
  mx[a2][b2] = 'c';
  if(bfs(a1, b1)) cout << 0;
  else{
    bfs2(a2, b2);
    int max = 1000001231;
    for(int i = 0; i < v1.size(); ++i){
      for(int j = 0; j < v2.size(); ++j){
        int cont = pow(v1[i].first - v2[j].first, 2) + pow(v1[i].second - v2[j].second, 2);
        if(cont < max) max = cont;
      }
    }
    cout << max;
  }

}