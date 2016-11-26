#include <bits/stdc++.h>
using namespace std;
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
typedef long long ll;

#define MAXN 1000001

ll a[MAXN];
unordered_map<ll, ll> dp;

ll cicles(ll k){
  if(!dp.count(k))
    dp[k] = 1+((k%2)?cicles(3*k+1):cicles(k/2));
  return dp[k];
}

int logs[MAXN];
int tbl[MAXN][20];

void initsptbl(){
  logs[0] = logs[1] = 0;
  for(int i=2;i<MAXN;i++){
    logs[i] = logs[i >> 1]+1;
  }
  for(int i=0;i<MAXN;i++){
    tbl[i][0] = i;
  }
  for(int k=1;(1<<k)<MAXN;k++){
    for(int i=0;i+(1<<k)<=MAXN;i++){
      int x = tbl[i][k-1];
      int y = tbl[i+(1<<(k-1))][k-1];
      tbl[i][k] = a[x] > a[y]? x : y; // rMq
    }
  }
}

ll rmq(int i, int j){
  int d = j-i;
  int k = logs[d];
  int x = tbl[i][k];
  int y = tbl[j-(1<<k)+1][k];
  return max(a[x],a[y]);
}

int main(){
  dp[1] = 1;
  for(int i=1;i<MAXN;i++){
    a[i]=cicles(i);
    //DB(i) DBL(a[i])
  }
  initsptbl();
  int l, r;
  while(cin >> l >> r){
    cout<<l<<" "<<r<<" "<<rmq(min(l,r), max(l,r))<<endl;
  }
}
