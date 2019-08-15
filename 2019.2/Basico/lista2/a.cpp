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

int main(){
  cout << fixed << setprecision(12);
  int n;
  int arr[MAXS];
  cin >> n;
  int su= 0;
  for(int i = 0;  i < n; ++i){
    cin >> arr[i];
    su+=arr[i];
  }
  cout << double(su)/n << endl;
}