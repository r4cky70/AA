#include <bits/stdc++.h>
#define MAXS 1000000007

#define mp(a, b) make_pair(a,b)
#define pb push_back
#define BZ freopen("input.txt", "r", stdin)

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;

int n, m;
string field[107];
queue <pii> fila;

bool inside(int x, int y){
  return (x >= 0 && x < n && y >= 0 && y < m);
}


void bfs(int x, int y){
  fila.push(mp(x, y));
  while(!fila.empty()){
    x = fila.front().first; y = fila.front().second;
    field[x][y] = '*';
    for(int i = -1; i < 2; ++i){
      for(int j = -1; j < 2; ++j){
        if(inside(x + i, y + j) && field[x + i][y + j] == '@'){
          fila.push(mp(x + i, y + j));
        }
      }
    }
    fila.pop();
  }
}


int main(){
  while(cin >> n >> m, n != 0 || m != 0){
    
    for(int i = 0; i < n; ++i){
      cin >> field[i];
    }
    int cont = 0;
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        if(field[i][j] != '*'){
          cont++;
          bfs(i, j);
        }
      }
    }
    cout << cont << endl;
  }

}