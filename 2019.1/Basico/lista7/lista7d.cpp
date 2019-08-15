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

int n, m;

priority_queue <pair<int, pii>, vector<pair<int, pii> > , greater<pair<int, pii>> >  edges;
int pai[MAXS];
int pesos[MAXS];

int find(int a){
  if(a == pai[a]) return a;
  return pai[a] = find(pai[a]);
}

void uni(int a, int b){
  int A = find(a);
  int B = find(b);

  if(A == B) return;

  if(pesos[A] < pesos[B]){
    pai[A] = B;
    pesos[B] += pesos[A];

  } 
  else {
    pai[B] = A;
    pesos[A] += pesos[B];
  }
}

int main(){
  int t, u, v;
  while(cin >> n >> m, n != 0 || m != 0){
    iota(pai, pai + n+1, 0);
    fill(pesos, pesos + n+1, 1);
    int total = 0;
    for(int i = 0; i < m; ++i){
      cin >> t >> u >> v;
      edges.push(mp(v, mp(t, u)));
      total += v;
    }
    int cont = 0;
    int ans = 0;
    int v1, v2;
    while(!edges.empty()){
      int v1 = edges.top().second.first, v2 = edges.top().second.second;
      if(find(v1) != find(v2)){
        uni(v1, v2);
        cont++;
        ans += edges.top().first;
      }
      edges.pop();
    }
    cout << total - ans << endl;
  }
}