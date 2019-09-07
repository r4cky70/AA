#include <bits/stdc++.h>
#define MAXS 500007
#define INF 2147483647

#define mp(a, b) make_pair(a,b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define STREE int bch = no*2, mid = (l+r)/2
#define ALL(a) a.begin(), a.end()

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 

bool mx[57][57];
bool vis[57][57];


int n, m;

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      cin >> mx[i][j];
    }
  }
  vector<pii> ad;
  for(int i = 0; i < n-1; ++i){
    for(int j = 0; j < m-1; ++j){
      if(mx[i][j] == 1 && mx[i+1][j] == 1 && mx[i+1][j+1] == 1 && mx[i][j+1] == 1){
        vis[i][j] = 1; vis[i+1][j] = 1;vis[i][j+1] = 1; vis[i+1][j+1] = 1;
        ad.push_back({i+1, j+1});
      }
    }
  }
  bool flag = true;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(mx[i][j] == 1 && vis[i][j] == 0) flag = false;
    }
  }
  if(!flag) cout << -1;
  else{
    cout << ad.size() << "\n";
    for(int i = 0; i < ad.size(); ++i){
      cout << ad[i].first << " " <<  ad[i].second << "\n";
    }
  }
}