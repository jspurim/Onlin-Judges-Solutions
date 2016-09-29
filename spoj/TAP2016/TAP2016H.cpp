#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
#else
#define DB(x) 
#define DBL(x) 
#endif
double dpv[1000][1000];
bool dp[1000][1000];

int n, x, y;

double E(int k){
    return (k+1 == y)?1:0;
}

int pairs(int k){
  return ((k*k)-k)/2;
}

double F(int b, int w){
  if(b<0 || w<0) return 0;
  if(b == 0 && w==0){
    return E(0);
  }
  if(!dp[b][w]){
    double t = pairs(b+w+1);
    DB(b) DB(pairs(b)) DB(w) DB(pairs(w)) DB(w*b) DBL(t)
    dp[b][w] = true;
    dpv[b][w] = 0;
    dpv[b][w] += b*E(b+w);
    dpv[b][w] += pairs(w)*F(b,w-1);
    dpv[b][w] += pairs(b)*F(b-1,w);
    dpv[b][w] += w*F(b,w-1);
    dpv[b][w] += b*w*F(b,w-1);
    dpv[b][w] /= t;
    DB(b) DB(w) DBL(dpv[b][w]);
  }
  return dpv[b][w];
}

int main(){
  memset(dp, 0, sizeof dp);
  cout<<setprecision(4)<<fixed;
  cin >> n >> x >> y;
  int w, b;
  b = x-1;
  w = n-b-1;
  cout<<F(b,w)<<endl;
}
