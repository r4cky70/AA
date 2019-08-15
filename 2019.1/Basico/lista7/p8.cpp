#include <bits/stdc++.h>
#define INF 1234567890
#define MAXS 507

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, t;
int adj[MAXS][MAXS];
vector<pii > edges[MAXS];
int dis[MAXS];

int dijkstra(int a, int b){
  for(int i =0; i <= n; ++i) dis[i] = INF;
  dis[a] = 0;
  priority_queue<pii , vector<pii >, greater<pii > > fila;
  fila.push(mp(0, a));
  while(!fila.empty()){
    int peso = fila.top().first;
    int node = fila.top().second;
    fila.pop();
    if(node == b) return peso;
    if(peso > dis[node]) continue;
    for(pii it : edges[node]){
      if(peso + it.first < dis[it.second]){
        dis[it.second] = peso + it.first;
        fila.push(mp(dis[it.second], it.second));
      }
    }
  }
  return -1;
}




int main(){
  int a, b, c;
  while(cin >> n >> m, !(n == 0 && m == 0)){
    memset(adj, -1, sizeof adj);
    for(int i = 0; i < m; ++i){
      cin >> a >> b >> c;
      if(adj[b][a] != -1){
        adj[b][a] = 0;
        adj[a][b] = 0;
      }
      else adj[a][b] = c;
    }
    for(int i = 0; i <= n; ++i){
      for(int j = 0; j <= n; ++j){
        if(adj[i][j] != -1){
          edges[i].pb(mp(adj[i][j], j));
        }
      }
    }
    cin >> t;
    for(int i = 0; i < t; ++i){
      cin >> a >> b;
      int temp = dijkstra(a, b);
      if(temp == -1) cout << "Nao e possivel entregar a carta\n";
      else cout << temp << "\n";
    }
    cout << "\n";
    for(int i = 0; i <= n; ++i) edges[i].clear();
  }
}