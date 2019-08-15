#include <bits/stdc++.h>
#define MAXS 10007

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define BZ freopen("input.txt", "r", stdin)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
int x, y;
vi edge[MAXS];
int vis[MAXS];
bool loop = false;

void dfs(int x){
  vis[x] = 1;
  for(int i = 0; i < edge[x].size(); ++i){
    if(vis[edge[x][i]] == 0){
      dfs(edge[x][i]);
    }else if(vis[edge[x][i]] == 2) loop = true;
  }
  vis[x] = 2;
}


int main(){
  cin >> n >> m;
  for(int i = 0;i < m; ++i){
    cin >> x >> y;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  dfs(1);
  if(loop) cout << "NO\n";
  else{
    for(int i = 1; i < n; ++i){
      if(vis[i] != 2) {cout << "NO\n";return 0;}
    }
    cout << "YES\n";
  }

}