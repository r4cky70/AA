#include <bits/stdc++.h>
#define MAXS 300007
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

int n , q , arr[MAXS];
int sq;
vector<pair<int, pii>> vec;
vector <pii> ans;
int dic[1000007];

bool func(pair<int, pii> c, pair<int, pii>  d){
  pii a = c.second, b = d.second;
  return (a.first/sq == b.first/sq ? a.second < b.second: a.first < b.first);
}

void solve(){
  int p1 = vec[0].second.first, p2 = vec[0].second.second;
  int ola = 0;
  for(int i = p1; i <= p2; ++i){
    if(dic[arr[i]] == 0) ola++;;
    dic[arr[i]]++;
  }
  ans.pb(mp(vec[0].first, ola));
  for(int i = 1; i < vec.size(); ++i){
    int a = vec[i].second.first, b = vec[i].second.second;
    while(p1 < a) {
      dic[arr[p1]]--;
      if(dic[arr[p1]] == 0) ola--;
      p1++;
    }
    while(p1 > a) {
      p1--;
      if(dic[arr[p1]] == 0) ola++;
      dic[arr[p1]]++;
    }
    while(p2 < b){
      p2++;
      if(dic[arr[p2]] == 0) ola++;
      dic[arr[p2]]++;
    } 
    while(p2 > b) {
      dic[arr[p2]]--;
      if(dic[arr[p2]] == 0) ola--;
      p2--;
    }
    ans.pb(mp(vec[i].first, ola));;
  }
}

int main(){
  FASTIO;
  cin >> n;
  sq = sqrt(n);
  for(int i = 0; i < n; ++i){
    cin >> arr[i];
  }
  cin >> q;
  int a, b;
  for(int i = 0; i < q; ++i){
    cin >> a >> b;
    vec.pb(mp(i, mp(a-1, b-1)));
  }
  sort(all(vec), func);
  solve();
  sort(all(ans));
  for(auto it : ans){
    cout << it.second << "\n";
  }

}