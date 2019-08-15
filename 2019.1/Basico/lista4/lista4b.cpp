#include <bits/stdc++.h>
#define MAXS 200007
#define make_pair(a, b) mp(a,b)

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

string s, s1;

int main(){
  ios::sync_with_stdio(false );
  cin.tie(0);
  cin >> s >> s1;
  cout << ((s == s1) ? s : "1") << '\n';
}