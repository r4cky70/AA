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

int zf[MAXS];
int acu[MAXS];
int freq[MAXS];
string s;

void zfunc(string s) {
  for (int i = 1, l = 0, r = 0; i < s.size(); ++i) {
    if (i <= r) zf[i] = min (r - i + 1, zf[i - l]);
    while (i + zf[i] < s.size() && s[zf[i]] == s[i + zf[i]]) ++zf[i];
    if (i + zf[i] - 1 > r) l = i, r = i + zf[i] - 1;
  }zf[0] = s.size();
}

int main(){
  FASTIO;
  cin >> s;
  zfunc(s);
  for(int i = 0; i < s.size(); ++i){
    freq[zf[i]]++;
  }
  for(int i = MAXS-2; i >=0; --i){
    acu[i] = freq[i]+acu[i+1];
  }
  vector<pii> ans;
  for(int i =s.size()-1; i >= 0; --i){
    if(zf[i] != 0  && zf[i] == s.size()-i){
      ans.pb(mp(zf[i], acu[zf[i]]));
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for(auto it : ans){
    cout << it.first << " " << it.second << "\n";
  }
}