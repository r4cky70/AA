#include <bits/stdc++.h>
#define MAXS 100007
#define INF 2234567890

#define make_pair(a, b) mp(a,b)
#define pb push_back
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;
typedef vector < pii > vpii;

int mylower(vi a, int l, int r, int v){
  int mid = (l+r)/2;
  if(l == r) return l;
  else if(a[mid] >= v){
    return mylower(a, l, mid, v);
  }else{
    return mylower(a, mid+1, r, v);
  }
}
int myupper(vi a, int l,int r, int v){
  int mid = (l+r)/2;
  if(l == r) return l;
  else if(a[mid] <= v){
    return myupper(a, mid+1, r, v);
  }else{
    return myupper(a, l, mid, v);
  }
}



int main(){
  vi a;
  for(int i = 0; i < 8; ++i){
    a.pb(i*2);
  }
  for(int i = 0; i < 8; ++i){
    cout << a[i] << " ";
  }cout << endl;
  cout << mylower(a, 0, a.size()-1, 2) << endl;
  cout << myupper(a, 0, a.size()-1, 2) << endl;
}