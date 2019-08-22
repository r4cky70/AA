#include <bits/stdc++.h>
#define MAXS 10007
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m, k;

vi arr[MAXS];


int main(){
  cin >> n >> m;
  for(int i = 0; i < m; ++i){
    cin >> k;
    int a;
    for(int j = 0; j < k; ++j){
      cin >> a;
      arr[i].pb(a);
    }
  }
  bool falg = true;
  for(int i = 0; i < m; ++i){
    set<int> pos, neg;
    bool thi = false;
    for(int j = 0; j < arr[i].size(); ++j){
      if(arr[i][j] > 0){
        if(neg.find(-arr[i][j]) != neg.end()){
          thi = true;
          break;
        }else{
          pos.insert(arr[i][j]);
        }
      }else{
        if(pos.find(-arr[i][j]) != pos.end()){
          thi = true;
          break;
        }else neg.insert(arr[i][j]);
      }
    }
    if(thi == false) falg = false;
  }
  cout << (falg ? "NO\n" : "YES\n");
}