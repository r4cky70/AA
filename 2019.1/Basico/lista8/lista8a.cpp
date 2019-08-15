#include <bits/stdc++.h>
#define MAXS 500007

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define inp freopen("input.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
ll lista1[MAXS], lista2[MAXS];



int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  ll s1 = 0, s2 = 0;
  for(int i = 0; i < n; ++i){
    cin >> lista1[i];
    s1 += lista1[i];
  }
  cin >> m;
  for(int j = 0; j < m; ++j){
    cin >> lista2[j];
    s2 += lista2[j];
  }
  ll j = 0, sa = 0, sb = 0;
  ll i = 0;
  ll ans = n;
  if(s1 != s2) cout << "-1\n";
  else{
    while(i < n && j < m){
      // cout << sa << "  " << sb << endl;
      if(sa == 0) sa+=lista1[i];
      if(sb == 0) sb+=lista2[j];
      if(sa == sb){
        sa = 0; sb = 0;
        ++i; ++j;
      }
      else if(sa < sb){
        ans--;
        ++i;
        if(i == n) break;
        sa+=lista1[i];
      }
      else{
        j++;
        if(j == m) break;
        sb+=lista2[j];
      }
    }
    cout << ans << endl;
  }
}