#include <bits/stdc++.h>
#define MAXS 1007
#define INF 1000000

#define mp(a, b) make_pair(a,b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define STREE int bch = no*2, mid = (l+r)/2
#define all(a) a.begin(), a.end()

using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int n, m, t;

struct studante{
  int cursos[101];
  studante(){
    for(int i = 0; i < 101; i++)
      cursos[i] = -1;
  }
  pair<long double, int> operator ^(const studante s){
    long double dist = 0;
    int max_c = -1;
    int nota = -1;
    int cont = 0;
    for(int i = 1; i <= 100; i++){
      if(cursos[i] == -1 && s.cursos[i] != -1){
        if(s.cursos[i] > nota){
          nota = s.cursos[i];
          max_c = i;
        }
      }
      if(cursos[i] != -1 && s.cursos[i] != -1){
        cont += 1;
        dist += (cursos[i] - s.cursos[i]) * (cursos[i] - s.cursos[i]) ; 
      }
      
    }
    if( ! cont){
      return {INF, max_c};
    }
    return {sqrt(dist), max_c};
  }
};

pair<long double, int> matrix[101][101];

int main(){
  int n, m;
  cin >> n >> m;
  studante ar[n];

  for(int i = 0; i < n; i++){
    int qtd_c;
    cin >> qtd_c;
    ar[i] = studante();
    
    for(int j = 0; j < qtd_c; j++){
      int curso, nota;
      cin >> curso >> nota;
      ar[i].cursos[curso] = nota;
    }
  }
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i != j){
        matrix[i][j] = ar[i]^ar[j];
      }
    }
  }

  for(int i = 0; i < n; i++){
    int menor = INF + 1;
    int indice = -1;
    for(int j = 0;  j < n; j++){
      if(i == j)
        continue;
      if(menor > matrix[i][j].first){
        menor = matrix[i][j].first;
        indice = j;
      }
    }
    if(matrix[i][indice].second == -1)
      cout << -1 << endl;
    else
      cout << matrix[i][indice].second << endl;
  }

}

// int courses[MAXS][MAXS];
// int n, m, t;

// bool func(pii a, pii b){
//   if(a.first == b.first){
//     return a.second > b.second;
//   }return a.first < b.first;
// }


// int main(){
//   cin >> n >> m;
//   memset(courses, -1, sizeof courses);
//   for(int i = 1; i <= n; ++i){
//     cin >> t;
//     int a, b;
//     for(int j = 0; j < t; ++j){
//       cin >> a >> b;
//       courses[i][a] = b;
//     }
//   }
//   for(int i = 1; i <= n; ++i){ // classmate's turn
//     double mindist = 10000000; vector<pii>ntake;
//     for(int j = 1; j <= n; ++j){ // all classmates
//       if(i == j) continue;
//       int d = INF; vector<pair<int, int> >notaken;
//       for(int k = 1; k <= 100; ++k){
//         if(courses[i][k] == -1 && courses[j][k] != -1){
//           notaken.push_back(mp(courses[j][k], k));
//         }else if(courses[i][k] != -1 && courses[j][k] != -1){
//           if(d == INF) d = pow((courses[i][k] - courses[j][k]), 2);
//           else d += pow(courses[i][k] - courses[j][k], 2);
//         }
//       }
//       if(mindist > sqrt(d)){
//         ntake = notaken;
//         mindist = d;
//       }
//     }
//     sort(all(ntake), func);
//     if(ntake.size() == 0) cout << -1 << "\n";
//     else{
//       cout << ntake[0].second <<  "\n";
//     } 
//   }
// }
