#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int coins [5] = {50, 25, 10, 5, 1};

ll dp[8000][5];
ll w(int v, int c){  
  if(v < 0) return 0;
  if(c >= 5) return 0;
  if(v == 0) return 1;
  if(dp[v][c] == -1){
    dp[v][c] = w(v-coins[c], c) + w(v, c+1);
  }
  return dp[v][c];
}

int main(){
  int k;
  memset(dp, -1, sizeof dp);
  while(cin >> k){
    cout<<w(k,0)<<endl;
  }
}
