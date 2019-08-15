#include <bits/stdc++.h>
#define MAXS 107

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define BZ freopen("input.txt", "r", stdin)
#define BX freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int t, n, m, l;
int x, y;
int cont;

vi edge[MAXS];
bitset<MAXS> vis;

void dfs(int x){
  vis[x] = true;
  cont++;
  for(int i = 0; i < edge[x].size(); ++i){
    int temp = edge[x][i];
    if(!vis[temp]){
      dfs(temp);
    }
  }
}



int main(){

  cin >> t;
  for(int i = 0; i < t; ++i){

    cont = 0;
    for(int j = 0; j < MAXS; ++j) edge[j].clear();
    vis.reset();
    cin >> n >> m >> l;
    for(int j = 0; j < m; ++j){
      cin >> x >> y;
      edge[x].pb(y);

    }
    for(int j = 0; j < l; ++j){
      cin >> x;
      if(!vis[x])dfs(x);
    }
    cout << cont << '\n';
  }
}