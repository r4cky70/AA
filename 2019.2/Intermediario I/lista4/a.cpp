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
#define FASTIO ios::sync_with_stdio(false); cin.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, q, arr[MAXS];
int sq;
unordered_map<int, int> dic;

struct call{
  int id;
  int l;
  int r;
  int ans;
  call(int a, int b, int c){
    id = a; l = b; r = c;
  }
  bool operator < (const call e){
    return id < e.id;
  }
};
vector<call> fila;

bool func(call a, call b){
  return (a.l/sq == b.l/sq ? a.r < b.r : a.l < b.l);
}

void solve(){
  int p1 = fila[0].l, p2 = fila[0].r;
  int ans = 0;
  for(int i = p1; i <= p2; ++i){
    dic[arr[i]]++;
    if(dic[arr[i]] == arr[i])++ans;
    else if(dic[arr[i]] == arr[i]+1)--ans;
  }
  fila[0].ans = ans;
  for(int i = 1; i < fila.size(); ++i){
    int a = fila[i].l, b = fila[i].r;
    while(p1 < a){
      dic[arr[p1]]--;
      if(dic[arr[p1]] == arr[p1]) ++ans;
      else if(dic[arr[p1]] == arr[p1]-1) --ans;
      p1++;
      // cout << ans << endl;
    }
    while(p1 > a){
      p1--;
      dic[arr[p1]]++;
      if(dic[arr[p1]] == arr[p1]) ++ans;
      else if(dic[arr[p1]] == arr[p1]+1) --ans;
      // cout << ans << endl;
    }
    while(p2 < b){
      p2++;
      dic[arr[p2]]++;
      if(dic[arr[p2]] == arr[p2]) ++ans;
      else if(dic[arr[p2]] == arr[p2]+1) --ans;
      // cout << ans << endl;
    }
    while(p2 > b){
      dic[arr[p2]]--;
      if(dic[arr[p2]] == arr[p2]) ++ans;
      else if(dic[arr[p2]] == arr[p2]-1) --ans;
      // cout << ans << endl;
      p2--;
    }
    fila[i].ans = ans;
  }
}


int main(){
  FASTIO;
  cin >> n >> q;
  sq = sqrt(MAXS);
  for(int i = 0; i < n; ++i){
    cin >> arr[i];
  }
  int a, b;
  for(int i = 0; i < q; ++i){
    cin >> a >> b;
    fila.pb(call(i, a-1, b-1));
  }
  sort(all(fila), func);
  solve();
  sort(all(fila));
  for(auto it : fila){
    cout << it.ans << "\n";
  }
}