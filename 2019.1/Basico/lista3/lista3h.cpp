#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector <int> vi;
typedef pair <int, int> pii;

#define mp make_pair

const int MAXS = 1007;

string s;
int cont, contt;
stack <char> pilha;


int main(){
  cin >> s;
  cont = 0;
  for(int i = 0; i < s.size(); ++i){
    if(pilha.empty()){
      pilha.push(s[i]);
    }
    else if(pilha.top() == s[i]){
      pilha.pop();
      cont++;
    }
    else pilha.push(s[i]);
  }
  printf(cont % 2 ? "Yes\n":"No\n");

}