#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector <int> vi;
typedef pair <int, int> pii;

#define mp make_pair

const int MAXS = 200007;

int n;
map <string, int> dic;
string s;
string saida;

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s;
    if(!dic[s]) {
      dic[s] = 1;
      saida += "OK\n";
    }
    else{
      saida += s + to_string(dic[s]) + '\n';
      dic[s]++;
    }
  }
  cout << saida;
}
