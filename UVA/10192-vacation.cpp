#include <bits/stdc++.h>
using namespace std;

string s,t;

int dp[200][200];

int f(int i, int j){
  if(i >= s.size() || j >= t.size()) return 0;
  if(dp[i][j] == -1){
    dp[i][j] = 0;
    if(s[i] == t[j]) dp[i][j] = f(i+1,j+1)+1;
    dp[i][j] = max(dp[i][j], f(i,j+1));
    dp[i][j] = max(dp[i][j], f(i+1,j));
  }
  return dp[i][j];
}

int main(){
  int c=0; 
  while(true){
    c++;
    getline(cin, s);
    if(s == "#") break;
    getline(cin, t);
    memset(dp,-1,sizeof dp);
    cout<<"Case #"<<c<<": you can visit at most "<<f(0,0)<<" cities."<<endl;
  }
}
