#include <bits/stdc++.h>
#define MAXS 100007
#define INF 2147483647

#define mp(a, b) make_pair(a,b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define all(a) a.begin(), a.end()

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;
#define FASTIO ios::sync_with_stdio(false);cin.tie(0)
#define debugarr(a, b) for(int i=0;i<b;++i)\
cout<< a[i] << " "; cout<<"\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int arr[MAXS];
int z[MAXS];
string s;

void kmp(string s){
  for(int i= 1; i < s.size(); ++i){
    int m = arr[i-1];
    while(m>0&&s[i]!=s[m]) m=arr[m-1];
    if(s[i]==s[m]) ++m;
    arr[i] = m;
  }
}
void func(string s){
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
  cin >> s;
  kmp(s);func(s);
  debugarr(arr, s.size());
  debugarr(z, s.size());
}