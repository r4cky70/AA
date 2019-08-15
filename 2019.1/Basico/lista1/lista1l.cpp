#include <bits/stdc++.h>
#define MAXS 200007

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > ii;

map <char, int> word;
string a, b;

bool vis[MAXS];


int main(){
  cin >> a >> b;
  
  for(int i = 0; i < b.size(); i++){
    if(word[b[i]] == 0) word[b[i]] = 1;
    else word[b[i]]++;
  }

  int yay = 0, whoops = 0;

  for(int i = 0; i < a.size(); i++){
    if(word[a[i]] > 0){
      yay++;
      vis[i] = true;
      word[a[i]]--;
    }
  }

  for(int i = 0; i < a.size(); i++){
    if(!vis[i]){
      if(a[i] > 90){
        if(word[a[i] - 32] > 0){
          whoops++;
          word[a[i] - 32]--;
        }
      }
      else{
        if(word[a[i] + 32] > 0){
          whoops++;
          word[a[i] + 32]--;
        }
      }
    }
  }
  printf("%d %d\n", yay, whoops);
  

}
