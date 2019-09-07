#include <bits/stdc++.h>
#define MAXS 500007
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

int t;
string s;

int main(){
  cin >> t;
  int a, b, c;
  for(int k = 0; k < t; ++k){
    cin >> a >> b >> c;
    cin >> s;
    int cont = 1;
    vi to;
    bool flag = false;
    for(int i = 0; i < s.size(); ++i){
      if(s[i]=='0' && flag == false) ++cont;
      else if(s[i] == '0' && flag == true){
        to.push_back(cont);
        cont = 0;
        flag = false;
      }
      else if(s[i] == '1' && flag == true){
        ++cont;
      }else{
        to.push_back(cont);
        cont=0;
        flag = true;
      }
    }
    to.push_back(cont);
    flag = false;
    int ans = 0;
    for(int i = 0; i < to.size(); ++i){
      if(flag == false){
        ans+= (to[i]-1)*b;
        ans += 2*b;
        ans
      }
      else if(flag == true){
        if(i%2){
          ans+= 2*c*to[i];
        }
      }
    }
  }
  
}