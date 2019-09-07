#include <bits/stdc++.h>
#define MAXS 100007
#define INF (int)__builtin_inf()

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


// template<typename T>
// void teste2 (T (*func)()){
//   func();
// }

void teste(vector<int> v, int a){
  for(int i = 0; i < v.size(); i+=a){
    cout << v[i] << endl;
  }
}

int main(){
  string s = "hello world";
  vector<int> yo{1, 2, 3, 4, 5};
  // teste(yo, 2);
  // auto f = [&yo, a = 2]{for(int i = 0; i < yo.size(); i+=a) cout<<yo[i]<<endl;};
  // for(int i = 0; i < 3; ++i){
  //   f();
  // }
  // int a = 64;
  // cout << (1<<__builtin_ctz(a)) << endl << (a&-a) << endl << __builtin_clz(1) - __builtin_clz(a) << endl;
  
  cout << (int)__builtin_inf() << endl << (ll)__builtin_inf() << endl << (int)(unsigned char)__builtin_inf() << endl;
  cout << INF << endl;
}