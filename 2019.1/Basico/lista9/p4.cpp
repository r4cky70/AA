#include <bits/stdc++.h>
#define INF 1234567890
#define MAXS 45

#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define INP freopen("input.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
int fib[MAXS];
int call[MAXS];

int solve(int a){
  if(fib[a] != -1) return fib[a];
  return fib[a] = solve(a-1) + solve(a-2);

}


int main(){
  int t;
  memset(fib, -1, sizeof fib);
  fib[0] = 0; fib[1] = 1;
  call[0] = 0; call[1] = 0;
  scanf("%d", &t);
  for(int i = 2; i < 40; ++i){
    call[i] = 2 + call[i - 1] + call [i - 2];
  }
  for(int i =0 ;i < t; ++i){
    scanf("%d", &n);
    solve(n);
    printf("fib(%d) = %d calls = %d\n", n, call[n], fib[n]);
  }
}