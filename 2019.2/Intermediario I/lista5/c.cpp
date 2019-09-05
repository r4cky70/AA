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

int arr[MAXS];
string s;

void kmp(){
	int i = 0, j = -1;
	arr[0] = -1;
	while(i < s.size()){
		while(j >= 0 && s[i] != s[j]) j = arr[j];
		i++; j++;
		arr[i] = j;
	}
}

int main(){
  int t;
  cin >> t;
  int a = t;
  while(t--){
    if(t < a-1) cout << "\n";
    cin >> s;
    kmp();
    int ans = 0;
    int temp = s.size() - arr[s.size()];
    if((arr[s.size()] % temp == 0)) cout << temp << "\n";
    else cout << s.size() << "\n";
    
  }
}