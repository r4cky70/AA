#include <bits/stdc++.h>
#define MAXS 100007
#define INF 1234567890

#define mp(a, b) make_pair(a,b)
#define pb push_back
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;

int arr[107];

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  for(int  i =0; i < a; ++i){
    cin >> arr[i];
  }
  int ans = 0;
  for(int i =0; i < a; ++i){
    int piv = c;
    int run = 0;
    int cont = 3;
    bool flag = true;
    int p1 = i; int p2 = i+1;
    while(cont >= 3){
      cont = 0;
      if(flag) ++cont;
      flag = false;
      while(p1>=0){
        if(arr[p1] == piv){
          ++cont;
          --p1;
        }else break;
      }
      while(p2<a){
        if(arr[p2] == piv){
          ++cont;
          ++p2;
        }else break;
      }
      if(p1>=0){
        piv = arr[p1];
      }else if(p2 < a) piv = arr[p2];
      if(cont >=3) run+=cont;
    }
    ans = max(run-1, ans);
  }
  cout << ans;
}