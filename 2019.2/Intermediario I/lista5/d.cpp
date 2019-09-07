#include <bits/stdc++.h>
#define MAXS 600007
#define INF 2147483647

#define mp(a, b) make_pair(a,b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define all(a) a.begin(), a.end()
#define FASTIO ios::sync_with_stdio(false); cin.tie(0)
#define debugarr(a, b) for(int i=0;i<b;++i)\
cout<< a[i]; cout<<endl

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int t;
string alfa, s, e;
unordered_map<char, int> key;
vi ans;
int arr[MAXS];

int kmp(string a, string s){
  string t = a+(char)0+s;
  int cont = 0;
  for(int i = 1; i < t.size(); ++i){
    int m = arr[i-1];
    while(m > 0 && t[i] != t[m]) m=arr[m-1];
    if(t[i] == t[m]) m++;
    arr[i] = m;
    if(arr[i] > 0 && arr[i]%a.size() == 0) cont++;
  }
  return cont;
}


int main(){
  cin >> t;
  while(t--){
    key.clear();
    ans.clear();
    cin >> alfa;
    for(int i = 0; i < alfa.size(); ++i) key[alfa[i]] = i;
    cin >> s;
    cin >> e;
    for(int k = 0; k < alfa.size(); ++k){
      if(kmp(s, e) == 1) ans.pb(k);
      for(int i = 0; i < s.size(); ++i){
        s[i] = alfa[(key[s[i]]+1)%alfa.size()];
      }
    }
    if(ans.size() == 0) cout << "no solution\n";
    else if(ans.size() == 1) cout << "unique: " << ans[0] << "\n";
    else {
      cout << "ambiguous:";
      for(auto it: ans) cout << " " << it;
      cout << "\n";
    }
  }
}