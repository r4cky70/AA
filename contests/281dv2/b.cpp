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

int n, m, o;

int main(){
  cin >> n >> m >> o;
  int mini = 0, maxi = 0;
  for(int i = 0; i < n; ++i){
    mini += pow(2, m-1);
    if(m > 1) m--;
  }
  int k = 0 ;
  for(int i = 0; i < n; ++i){  
    maxi += pow(2, k);
    if(k < o-1) ++k;
  }
  cout << mini << " " << maxi << endl;
}