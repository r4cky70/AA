#include <bits/stdc++.h>
#define MAXS 107

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define inp freopen("input.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, o;


struct ligacao{
  int peso;
  pair<int, int> cidades;
  int tipo;

  ligacao(int a, int c1, int c2, int d){
    peso = a;
    cidades = mp(c1, c2);
    tipo = d;
  }
};

bool compa(ligacao a, ligacao b){
  if(a.tipo != b.tipo){
    return a.tipo == 1;
  }
  return a.peso < b.peso;
}

vector<ligacao> edges;

struct unionfind{

  int pai[MAXS];
  int sz[MAXS];

  void setup(){
    iota(pai, pai + n, 0);
    fill(sz, sz + n, 1);
  }

  int find(int a){
    if(pai[a] == a) return a;
    return pai[a] = find(pai[a]);
  }

  void uni(int a, int b){
    int A = find(a), B = find(b);

    if(A == B) return;
    pai[A] = B;
  }
};


int kruskal(){
  unionfind root;
  root.setup();
  sort(edges.begin(), edges.end(), compa);

  int ans = 0;
  for(auto it : edges){
    int x = root.find(it.cidades.first), y = root.find(it.cidades.second);
    if(x != y){
      root.uni(x, y);
      ans += it.peso;
    }
  }
  return ans;
}



int main(){
  cin >> n >> m >> o;
  int t1, t2, t3;
  for(int i = 0; i < m; ++i){
    cin >> t1 >> t2 >> t3;
    ligacao rua(t3, t2, t1, 1);
    edges.pb(rua);
  } for(int i = 0; i < o; ++i){
    cin >> t1 >> t2 >> t3;
    ligacao rua(t3, t2, t1, 2);
    edges.pb(rua);
  }
  cout << kruskal() << endl;
}