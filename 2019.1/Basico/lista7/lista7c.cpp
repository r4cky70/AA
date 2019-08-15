#include <bits/stdc++.h>
#define INF 1234567891
#define MAXS 107

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define BZ freopen("input.txt", "r", stdin)
#define BX freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, u, v, w;

vector<pair<int, int> > lista[MAXS];
int dist[MAXS];

int dikstra(int a){
  fill(dist, dist + n+1, INF);
  dist[a] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > fila;
  fila.push(mp(0, a));
  while(!fila.empty()){
    int v = fila.top().second;
    int peso = fila.top().first;
    fila.pop();
    if(dist[v] < peso) continue;
    for(int i = 0; i < lista[v].size(); ++i){
      pii temp = lista[v][i];
      if(dist[temp.second] > temp.first + dist[v]){
        dist[temp.second] = temp.first + dist[v];
        fila.push(mp(dist[temp.second], temp.second));
      }
    }
  }
  int x = 0;
  for(int i = 0; i < n; ++i){
    if(dist[i] > x) x = max(x, dist[i]);
  }
  return x;
}




int main(){
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    cin >> u >> v >> w;
    lista[u].pb(mp(w, v));
    lista[v].pb(mp(w, u));
  }
  int ans = INF;
  for(int i = 0; i < n; ++i){
    int x = dikstra(i);
    if(x < ans) ans = min(x, ans); 
  }
  cout << ans << '\n';
}
