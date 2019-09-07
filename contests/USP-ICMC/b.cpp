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

vector<pii> vec;
int n;

bool func(pii a, pii b){
  if(a != b) return a.first < b.first;
  return a.second > b.second;
}
map<int, vector<ll>> dic;

int main(){
  
  ll a,b;
  cin>>a>>b;

  ll lim = (ll)sqrt(a);

  vector<ll> resp;

  for(ll i = 1;i<=lim;++i){

    if(a%i == 0){

      if(i%b == 0){ resp.push_back(i);}
      if(i!=(a/i)){
        if((a/i)%b == 0){resp.push_back(a/i);}
      }

    }

  }

  sort(resp.begin(),resp.end());
  for(int i = 0;i<resp.size();++i){
      cout<<resp[i];
      if(i+1>=resp.size()){
        cout<<endl;

      }else{

        cout<<" ";

      }

  }

}