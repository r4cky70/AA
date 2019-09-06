#include <bits/stdc++.h>
#define MAXS 100007
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
#define FASTIO ios::sync_with_stdio(false); cin.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, q;
int arr[MAXS];
int sq;
int limite[MAXS];
int jump[MAXS], last[MAXS];

void lim(){
  for(int i= 0; i < sq; ++i){
    limite[i] = sq*i-1;
  }
}


void build(int id){
  if(id+arr[id] >= n || id+arr[id] > lim[id/sq]){
    last[id] = id; jump[id]++;
  }else{
    jump[id]++;
    last[id] = 
  }
  while(id < lim)
}






int main(){
  sq = sqrt(MAXS);
  cin >> n >> q;
  for(int i=  0; i < n; ++i){
    cin >> arr[i];
  }
  int a, b, c;
  for(int  i = n-1; i > -1; --i){
    build(i);
  }
  while(q--){
    cin >> a;
    if(a == 1){
      cin >> b;
    }else{
      cin >> b >> c;
    }
  }
}