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
  
int n;
int arr[MAXS];

pii getprims(int a){
  int p = arr[n/2];
  int p1 = p;
  int p2 = p;
  
  bool flag = false;
  while(flag == false){
  flag = true;
    for(int i = 2; i < sqrt(p1); ++i){
      if(p1%i == 0){
        flag = false;
        break;
      }
    }
    ++p1;
  }
  bool falg = false;
  while(flag == false && p2 >= 2){
    for(int i = 2; i < sqrt(p2); ++i){
      if(p2%i == 0){
        flag = false;
        break;
      }
    }
    --p2;
  }
  return mp(p1, p2);
}


int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> arr[i];
  }
  sort(arr, arr+n);
  int p1, p2, p3, p4;
  int p = arr[n/2], l = arr[n/2+1];
  if(n%2){
    pii temp = getprims(p);
    p1 = temp.first;
    p2 = temp.second;
    ll ans = 1LL*INF*INF;
    ll cont = 0;
    ll cont2 = 0;
    for(int i = 0; i < n; ++i){
      cont += abs(arr[i] - p1);
      cont2 += abs(arr[i] - p2);
    }
    cout << min(cont, cont2) << endl;
  }
  else{
    pii temp1 = getprims(p);
    pii temp2 = getprims(l);
    p1 = temp1.first;
    p2 = temp2.second;
    ll ans = 1LL*INF*INF;
    ll cont = 0;
    ll cont2 = 0;
    ll cont3 = 0;
    ll cont4 = 0;
    for(int i = 0; i < n; ++i){
      cont += abs(arr[i] - p1);
      cont2 += abs(arr[i] - p2);
      cont3 += abs(arr[i] - p3);
      cont4 += abs(arr[i] - p4);
    }
    cout << min(min(min(cont, cont2), cont3), cont4) << endl;
  }
}