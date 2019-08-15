#include <bits/stdc++.h>
#define INF 1234567891
#define MAXS 507

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define BZ freopen("input.txt", "r", stdin)
#define BX freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
int h1, h2, e1, e2;
char mx[MAXS][MAXS];
bool vis[MAXS][MAXS];
int d1[4] = {1, 0, 0, -1}, d2[4] = {0, 1, -1, 0};

bool inside(int a, int b){
  return a < n && a > -1 && b < m && b > -1 && mx[a][b] != '#' && !vis[a][b];
}


int cont = 0;

int dijkstra(){
  priority_queue <pair < int, pii >, vector <pair< int, pii > >, greater <pair<int, pii > > > fila;
  fila.push(mp(0, mp(h1, h2)));
  vis[h1][h2] = 1;
  while(!fila.empty()){
    pii pos = fila.top().second;
    int peso = fila.top().first;
    fila.pop();
    if(mx[pos.first][pos.second] == 'E') return peso;
    for(int i = 0; i < 4; ++i){
      int x = pos.first + d1[i], y = pos.second + d2[i];
      if(inside(x, y)){
        if(mx[x][y] == 'E') return peso;
        fila.push(mp(peso + mx[x][y] - '0', mp(x, y)));
        vis[x][y] = 1;
      }
    }
  }
  return -1;
}






int main(){
  cin >> n >> m;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      cin >> mx[i][j];
      if(mx[i][j] == 'H'){h1 = i; h2 = j;}
      if(mx[i][j] == 'E'){e1 = i; e2 = j;}
      if(mx[i][j] == '.') mx[i][j] = '0';
    }
  }
  int x = dijkstra();
  if(x == -1) cout << "ARTSKJID\n";
  else cout << x << endl;
}