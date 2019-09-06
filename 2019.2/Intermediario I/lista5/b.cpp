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
#define FASTIO ios::sync_with_stdio(false); cin.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int z[MAXS];
int acu[MAXS];
int freq[MAXS];
string s;

void func(){
	int l = 0, r = 0;
	for(int i = 1; i < s.size(); i++){
		z[i] = max(0, min(z[i-l], r-i+1));
		while(i+z[i] < s.size() && s[z[i]] == s[i+z[i]]){
			l = i; r = i+z[i]; z[i]++;
		}
	}
	z[0] = s.size();
}

int main(){
  FASTIO;
  cin >> s;
  func();
  for(int i = 0; i < s.size(); ++i){
    freq[z[i]]++;
  }
  for(int i = MAXS-2; i >=0; --i){
    acu[i] = freq[i]+acu[i+1];
  }
  vector<pii> ans;
  for(int i =s.size()-1; i >= 0; --i){
    if(z[i] != 0  && z[i] == s.size()-i){
      ans.pb(mp(z[i], acu[z[i]]));
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for(auto it : ans){
    cout << it.first << " " << it.second << "\n";
  }
}