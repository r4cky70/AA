#include <bits/stdc++.h>


using namespace std;


int main(){
  int n;

  cin >>  n;
  if(n == 1){
    long long x, y;
    cin >> x >> y;
    cout << x - y << endl;
    return 0;
  }

  pair<int, int> ar[n];
  for(int i = 0; i < n; i++){
    int x, y;
    cin >> x >> y;
    ar[i] = {y,x};
  }
  sort(ar, ar + n);
  long long sum = 0;

  vector<long long int> res;

  for(int i = 0;  i < n; i++){
    sum+=ar[i].second;
    res.push_back(sum - ar[i].first);
  }


  long long int ma = res[0];

  for(int i = 1;i<res.size();++i){

    ma = max(ma,res[i]);

  }
  cout << ma << endl;





}