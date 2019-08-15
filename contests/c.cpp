#include <bits/stdc++.h>
#define INF 2034567890
#define MAXS 20007

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;

vi edges[MAXS];
vi gral;
bitset<MAXS> vis;
int ans;

void rem(int a){
  stack<int>pilha;
  pilha.push(a);
  vis[a] = true;
  while(!pilha.empty()){
    ans--;
    int x = pilha.top();
    pilha.pop();
    for(auto it : edges[x]){
      if(!vis[it] && edges[it].size() <= 2){
        pilha.push(it);
        vis[it] = 1;
      }
    }
  }
}


int main(){
  cin >> n >> m;
  int a, b;
  ans = n;
  for(int i = 0; i < m; ++i){
    cin >> a >> b;
    edges[a].pb(b);
    edges[b].pb(a);
  }
  int sta = 0, ka = 0;
  for(int i = 1; i <= n; ++i){
    if(edges[i].size() > ka){
      ka = edges[i].size();
      sta = i;
    }
    if(edges[i].size() == 1) gral.pb(i);
  }
  for(auto it : gral){
    rem(it);
  }
  rem(sta);
  cout << ans;
}