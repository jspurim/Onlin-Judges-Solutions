#include <bits/stdc++.h>
using namespace std;

int n, m;

typedef long long ll;
#define MOD 1000000007

ll dp1[1001][101];

ll coin(int k, int r){
  if(r == 0){
    return (k == 0)?1:0;
  }
  if(dp1[k][r] == -1){
    ll ans = 0;
    for(int i=1;i<=min(m,k);i++){
      ans += coin(k-i, r-1);
      ans %= MOD;
    }
    dp1[k][r] = ans;
  }
  return dp1[k][r];
}

ll dp2[101][101];

ll CnR(int n, int k){
  if(k == 0 || k == n) return 1;
  if(dp2[n][k] == -1){
    dp2[n][k] = (CnR(n-1, k)+CnR(n-1,k-1))%MOD;
  }
  return dp2[n][k];
}


int main(){
  int p1, p2;
  cin >> n >> m >> p1 >> p2;
  memset(dp1, -1, sizeof dp1);
  memset(dp2, -1, sizeof dp2);
  ll total = 0;
  for(int i=0; i<=n; i++){
    int N = n-i;
    ll ans = 0;
    for(int j=0; j<=N; j++){
      //cerr<<coin(p1, j)<<" "<<coin(p2, N-j)<<" "<<CnR(N, j)<<endl;
      ans += (((coin(p1, j)*coin(p2, N-j))%MOD)*CnR(N, j))%MOD;
      ans %= MOD;
    }
    ans *= CnR(n, i);
    total += ans;
    total %= MOD;
  }
  cout<<total<<endl;
}
