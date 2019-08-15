#include <bits/stdc++.h>
#define INF 1234567890
#define MAXS 45

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int t, n;
vector<pii > lista;

struct saco{
  int peso;
  int unid;
  int pac;
  saco(){
    peso = -1;
    unid = -1;
    pac = -1;
  }
  saco(int a, int b, int c){
    peso = a;
    unid = b;
    pac = c;
  }
}; 
saco asa[MAXS];

saco dp(int ind, int peso, int unid, int pac){
  saco ans = saco(peso, unid, pac);
  for(int i = ind; i < lista.size(); ++i){
    if(peso - lista[i].second >=0){
      saco res = dp(i+1, peso-lista[i].second, unid+lista[i].first, pac+1);
      if(res.unid > ans.unid) ans = res;
    }
  }
  return ans;
}


int main(){
  cin >> t;
  for(int i =0 ; i < t; ++i){
    cin >> n;
    int a, b;
    for(int j =0; j < n; ++j){
      cin >> a >> b;
      lista.pb(mp(a,b));
    }
    sort(lista.begin(), lista.end());
    reverse(lista.begin(), lista.end());
    saco ans = dp(0, 50, 0, 0);
    lista.clear();
    cout << ans.unid << " brinquedos\nPeso: " << 50 - ans.peso << " kg\nsobram(m) " << n-ans.pac << " pacote(s)\n\n";
  }
}