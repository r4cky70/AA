#include <bits/stdc++.h>
#define MAXS 50010

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define inp freopen("input.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;

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

    if(sz[A] < sz[B]){
      pai[A] = B;
      sz[B] += sz[A];
    }else{
      pai[B] = A;
      sz[A] += sz[B];
    }
  }
};

int kruskal(vector<pair<int, pair<int, int>>> &edges){
  unionfind root;
  root.setup();
  int ans = 0;
  sort(edges.begin(), edges.end());

  for(auto it : edges){
    int x = it.second.first, y = it.second.second;
    if(root.find(x) != root.find(y)){
      root.uni(x, y);
      ans += it.first;
    }
  }
  return ans;
}

int main(){
  int t1, t2, t3;
  while(cin >> n >> m, n != 0 && m != 0){
    vector <pair <int, pair<int, int>>> edges;
    for(int i= 0 ; i < m; ++i){
      cin >> t1 >> t2 >> t3;
      edges.pb(mp(t3, mp(t1, t2)));
    }
    cout << kruskal(edges) << endl;
    edges.clear();
  }

}