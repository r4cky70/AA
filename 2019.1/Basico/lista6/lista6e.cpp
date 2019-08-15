#include <bits/stdc++.h>
#define MAXS 200007

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define BZ freopen("input.txt", "r", stdin)
#define BX freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
vector<pii> lista[MAXS];
bitset<MAXS> vis;
vi anss;
set<int> ans;

int dfs(int x, int t){
  vis[x] = true;
  vi temp;
  if(t == 1){
    if(lista[x].size() == 0) return 0;
    for(int i = 0; i < lista[x].size(); ++i){
      if(!vis[lista[x][i].first]){
        int l = dfs(lista[x][i].first, lista[x][i].second);
        if(l != 0){
          temp.pb(l);
          ans.insert(l);
        }
      }
    }
    if(temp.size() >= 1) return temp[0];
    else return 0;
  }else{
    for(int i = 0; i < lista[x].size(); ++i){
      if(!vis[lista[x][i].first]){
        int l = dfs(lista[x][i].first, lista[x][i].second);
        if(l != 0){
          temp.pb(l);
          ans.insert(l);
        }
      }
    }
    if(temp.size() >= 1) return temp[0];
    else return x;
  }
}



int main(){
  int a, b, c;
  
  cin >> n;
  for(int i = 0; i < n - 1; ++i){
    cin >> a >> b >> c;
    lista[a].pb(mp(b, c));
    lista[b].pb(mp(a, c));
  }
  dfs(1, 1);
  // vis[1] = 1;
  // for(int i = 0; i < lista[1].size(); ++i){
  //   dfs(lista[1][i].first, lista[1][i].second);
  // }
  cout << ans.size() << '\n';
  for(auto i : ans) cout << i << ' ';
  
}