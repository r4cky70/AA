#include <bits/stdc++.h>
#define MAXS 25007
#define INF 2147483647

#define mp(a, b) make_pair(a,b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define STREE int branch = no*2, mid = (l+r)/2
#define all(a) a.begin(), a.end()

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;
#define FASTIO ios::sync_with_stdio(false); cin.tie(0);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;

ll mx[MAXS][25];
ll swi[MAXS][25];
ll dist[MAXS][25];

int dx[] = {-1, 0, 1};
int dy[] = {0, 1, 0};

bool inside(int x, int y){
  return (y >= 0 && y < m);
}


int dikjstra(){
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> fila;
  fila.push(mp(0, 0));
  while(!fila.empty()){
    int no = fila.top().second;
    int p = fila.top().first;
    for(int i = 0; i < 3; ++i){
      if(inside(x+dx[i], y +))
    }
  }
}


int main(){
  int t;
  cin >> t;
  while(t--){
    cin >> n >> m;
    int a, b, c;
    for(int i = 0;i < n; ++i){
      for(int j = 0; j < m; ++j){
        cin >> mx[i][j];
      }
    }
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m-1; ++j){
        cin >> swi[i][j];
      }
    }
  }
}