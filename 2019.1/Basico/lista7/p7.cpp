#include <bits/stdc++.h>
#define INF 1234567890
#define MAXS 105

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;

vector <pair<int, pair <int, int> > > pontos;
vector<pair<double, int > > edges[MAXS];
double dist[MAXS];

double dijkstra(int a, int b){
  for(int i = 0; i <= 101; ++i) dist[i] = INF;
  priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > fila;
  dist[a] = 0;
  fila.push(mp(0, a));
  while(!fila.empty()){
    double peso = fila.top().first;
    int no = fila.top().second;
    fila.pop();
    if(no == b) return dist[no];
    if(dist[no] < peso) continue;
    for(int i = 0; i < edges[no].size(); ++i){
      pair<double, int> p = edges[no][i];
      if(dist[p.second] > peso + p.first){
        dist[p.second] = peso + p.first;
        fila.push(mp(dist[p.second], p.second));
      }
    }
  }
  return -1;
}



int main(){
  int a, b, c;
  while(cin >> n, n != 0){
    for(int i = 0 ;i < n; ++i){
      cin >> a >> b >> c;
      pontos.pb(mp(c, mp(a, b)));
    }
    for(int i = 0; i < pontos.size(); ++i){
      for(int j = i+1; j < pontos.size(); ++j){
        double temp = sqrt(((pontos[i].second.first - pontos[j].second.first) * (pontos[i].second.first - pontos[j].second.first)) + ((pontos[i].second.second - pontos[j].second.second) * (pontos[i].second.second - pontos[j].second.second)));
        if(temp <= pontos[i].first){
          edges[i].pb(mp(temp, j));
        }
        if(temp <= pontos[j].first){
          edges[j].pb(mp(temp, i));
        }
      }
    }
    cin >> m;
    for(int i = 0; i < m; ++i){
      cin >> a >> b;
      double temp = dijkstra(a-1, b-1);
      cout << floor(temp) << "\n";
    }
    for(int i = 0; i <=n; ++i){
      edges[i].clear();
    }pontos.clear();
  }
}