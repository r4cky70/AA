#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector <int> vi;
typedef pair <int, int> pii;

#define mp make_pair

const int MAXS = 1007;


map <string, pair<string, string>> dic;
vector <string> that;
int n;
string s1, s2;

string fout(string s){
  while(true){
    string x = dic[s].first, y = dic[s].second;
    if(y == "") return s;
    s = y;
  }
}



int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> s1 >> s2;
    if(dic.find(s1) == dic.end()){
      that.push_back(s1);
      dic[s1] = make_pair("", s2);
      dic[s2] = make_pair(s1, "");
    }
    else {
      dic[s1].second = s2;
      dic[s2] = make_pair(s1, "");
    }
  }
  cout << that.size() << endl;
  for(int i = 0; i < that.size(); i++){
    cout << that[i] << " " << fout(that[i]) << endl;
  }
}