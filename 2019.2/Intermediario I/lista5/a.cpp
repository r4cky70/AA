#include <bits/stdc++.h>
#define MAXS 1000007
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

int arr[MAXS];

string s;

void kmp(string s){
  for(int i = 1; i < s.size(); ++i){
    int j = arr[i-1];
    while(j > 0 && s[i] != s[j]) j = arr[j-1];
    if(s[i] == s[j]) j++;
    arr[i] = j;
  }
}


int main(){
  cin >> s;
  kmp(s);
  int t = arr[s.size()-1];
  int ans;
  ans = arr[t-1];
  for(int i = 0; i < s.size()-1; ++i){
    if(arr[i] >= t) ans = t;
  }
  cout << (ans == 0 ? "Just a legend" : s.substr(0, ans)) << "\n";
}