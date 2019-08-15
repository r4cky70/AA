#include <bits/stdc++.h>
#define MAXS 507

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

string s;


bool check(int x){
  int y = x / 2;
  for(int i = 0; i <= y - 1; i++){
    if(s[i] != s[x - i - 1]){
      return false;
    }
  }
  return true;
}





int main(){
  cin >> s;
  int x = s.size();
  for(int i = x; i > x / 2; i--){
    if(!check(i)) {
      printf("%d\n", i);
      return 0;
    }
  }
  printf("0\n");
}