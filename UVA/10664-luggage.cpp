#include <bits/stdc++.h>
using namespace std;

int n;
int a[200];
bool dp[200][20];
bool v[200][20];
bool can(int d, int i){
  if(i == n)
    return d == 0;
  if(!v[d][i]){
    int d1 = d + a[i];
    int d2 = abs(d - a[i]);
    dp[d][i] = can(d1,i+1) || can(d2, i+1);
  }
  return dp[d][i];
} 

int main(){
  int t;
  cin >> t;
  string line;
  getline(cin, line);
  while(t--){
    memset(v, 0, sizeof v);
    getline(cin, line);
    stringstream ss(line);
    n=0;
    int k;
    while(ss >> a[n]){
      n++;
    }
    cout<<(can(0,0)?"YES":"NO")<<endl;
  }
}
