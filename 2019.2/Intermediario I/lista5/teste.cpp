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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int arr[MAXS];

void kmp(string s){
  arr[0] = 0;
  int m = 0;
  for(int i = 1; i < s.size(); ++i){
    while(m > 0 && s[i] != s[m]) m = arr[m];
    if(s[i] == s[m]) arr[i] = ++m;
  }
}


int main(){
  string s;
  cin >> s;
  kmp(s);
  for(int i = 0; i < s.size(); ++i){
    cout << arr[i] << " ";
  }cout << endl;
}