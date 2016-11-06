#include <bits/stdc++.h>
using namespace std;

vector<int> s;
vector<int> t;

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
  int n1, n2;
  int c=0;
  while(cin>>n1>>n2){
    if(n1+n2 == 0) break;
    c++;
    s.clear();
    t.clear();
    int k;
    for(int i=0;i<n1;i++){
      cin >> k;
      s.emplace_back(k);
    }
    
    for(int i=0;i<n2;i++){
      cin >> k;
      t.emplace_back(k);
    }
    memset(dp,-1,sizeof dp);
    cout<<"Twin Towers #"<<c<<endl<<"Number of Tiles : "<<f(0,0)<<endl<<endl;
  }
}
