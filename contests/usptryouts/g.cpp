#include <bits/stdc++.h>
#define MAXS 100007
#define INF 2147483647

#define mp(a, b) make_pair(a,b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define STREE int bch = no*2, mid = (l+r)/2
#define all(a) a.begin(), a.end()

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int arr[MAXS];
int pai[MAXS];
int n, m;

pii find(int a){
  if(pai[a] == a) return mp(arr[a], pai[a]);
  pii temp = find(pai[a]);
  arr[a] = min(temp.first, arr[a]);
  pai[a] = temp.second;
  return mp(arr[a], pai[a]);
}
void uni(int a, int b){
  if(pai[b] == b){
    pai[b] = a;
  }
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 1; i <= n; ++i){
    cin >> arr[i];
  }
  iota(pai, pai+MAXS, 0);
  char c;
  int a, b;
  for(int i = 0; i < m; ++i){
    cin >> c;
    if(c == '+'){
      cin >> a >> b;
      uni(a, b);
    }else{
      cin >> a;
      cout << find(a).first << "\n";
    }
  }
}