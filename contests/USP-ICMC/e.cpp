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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<vector<ll>> ar;
ll dp[MAXS][2];
vector<ll> maxmin(ll v,vector<ll> a){

  ll value = v;
  if(a[0] < v){
    value = a[0];
    a[0] = v;
  }
  if(a[1] > value){
    a[1] = value;
  }
  return a;
}

ll knap(ll atual, ll est,ll acu,ll value){

  if(atual>=n){
    return acu;
  }

  if(dp[atual][est]!=-1) return dp[atual][est];

  ll one = knap(atual+1,1,acu+abs(ar[atual][1]-value),ar[atual][0]);
  ll zero = knap(atual+1,0,acu+abs(ar[atual][0]-value),ar[atual][1]);

  return dp[atual][est] = max(one,zero);

}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(0);

  for(int i = 0;i<MAXS;++i){
    dp[i][0] = dp[i][1] = -1;
  }

  map<ll,vector<ll>> m;

  cin>>n;

  for(int i = 0;i<n;++i){

    ll id,v;
    cin>>id>>v;
    if(m.find(id)!=m.end()){
        m[id] = maxmin(v,m[id]);
    }else{
      vector<ll> a;
      a.push_back(v);
      a.push_back(v);
      m[id] = a;
    }

  }

  for(auto k:m){
    ar.push_back(k.second);
  }

  n = ar.size();
  
  cout<<max(knap(0,0,0,ar[0][1]),knap(0,1,0,ar[0][0]))<<endl;

}