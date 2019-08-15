#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector <int> vi;
typedef pair <int, int> pii;

#define mp make_pair

const int MAXS = 300007;
queue <int> pilha;


int main(){
  int n, yo;
  
  cin >> n;
  for(int i = 0; i < n; i++){
    scanf("%d", &yo);
    if(yo == 1){
      scanf("%d", &yo);
      pilha.push(yo);
    }
    else if(yo == 2){
      if(!pilha.empty()) pilha.pop();
    }
    else{
      if(!pilha.empty()) printf("%d\n", pilha.front());
      else printf("Empty!\n");
    }
  }
}