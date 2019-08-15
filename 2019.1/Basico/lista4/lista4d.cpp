#include <bits/stdc++.h>
#define MAXS 200007
#define make_pair(a, b) mp(a,b)
#define debug(a) cout << a << '\n';

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

ll n;
string s;
int lista[9] = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  ll si = (int)s.size();
  n = stoi(s) * si;
  for(int i = si - 2; i > -1; i--){
    n -= lista[i];
  }
  cout << n << '\n';
}