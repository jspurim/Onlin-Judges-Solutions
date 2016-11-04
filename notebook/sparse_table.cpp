#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000

typedef long long ll;

int logs[MAXN];
int tbl[MAXN][16];
ll a[MAXN];

void initsptbl(){
  logs[0] = logs[1] = 0;
  for(int i=2;i<100001;i++){
    logs[i] = logs[i >> 1]+1;
  }
  for(int i=0;i<MAXN;i++){
    tbl[i][0] = i;
  }
  for(int k=1;(1<<k)<MAXN;k++){
    for(int i=0;i+(1<<k)<=MAXN;i++){
      int x = tbl[i][k-1];
      int y = tbl[i+(1<<(k-1))][k-1];
      tbl[i][k] = a[x] < a[y]? x : y;
      //tbl[i][k] = a[x] > a[y]? x : y; // rMq
    }
  }
}

ll rmq(int i, int j){
  int d = j-i;
  int k = logs[d];
  int x = tbl[i][k];
  int y = tbl[j-(1<<k)+1][k];
  return a[x] < a[y]? x : y;
}

int main(){
  int i=0;
  for(int k : {1,3,5,2,2,4,5,1,2,4,5,5}){
    a[i++] = k;
    cerr<<k<<" ";
  }
  initsptbl();
  cerr<<endl;
  int x,y;
  while(cin >> x >> y){
    cerr<<rmq(x,y)<<" "<<a[rmq(x,y)]<<endl;
  }
}
