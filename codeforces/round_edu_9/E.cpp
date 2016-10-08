/*
 * Problem: http://codeforces.com/problemset/problem/632/E
 */

#include <bits/stdc++.h>
#define DB(x) cerr << #x << ": "<<x<<" ";
#define DBL(x) cerr << #x << ": "<<x<<endl;
using namespace std;

struct cpl{
  double r;
  double i;
  
  cpl() : r(0), i(0) {};
  cpl(double r, double i): r(r),i(i){};
  
  cpl operator + (cpl &c){
    return cpl(r + c.r, i + c.i);
  }
  
  cpl operator - (cpl &c){
    return cpl(r - c.r, i - c.i);
  }
  
  cpl operator * (cpl &c){
    return cpl(r * c.r - i * c.i,r * c.i + i * c.r);
  }
  
  void operator *= (cpl &c){
    double nr = (r * c.r - i * c.i);
    i=(r * c.i + i * c.r);
    r = nr;
  }
  
  double real(){
    return r;
  }
};

//typedef complex<double> cpl;
const cpl I(0,1);
cpl half(0.5,0);
const double TAU = 4*acos(0);


cpl aux[1<<21];

map<pair<int,bool>, cpl> dp;

cpl WN(int n, bool b){
  if(dp.find({n,b}) == dp.end()){
    double ang = (TAU/n) * (b ? -1 : 1);
    cpl wn(cos(ang), sin(ang));
    dp[{n,b}] = wn;  
  }
  return dp[{n,b}];
}

void FFT (cpl *a, int n, bool invert=false, int f=0, int s=1) {
  if (n == 1)  return;
  FFT(a, n/2,invert, f,s*2);   //E
  FFT(a,n/2,invert,f+s,s*2);   //O
 
  cpl wn=WN(n, invert); 
  cpl w(1,0);
  for (int i=0; i<n/2; ++i) {
    int e = f+(s*i*2);
    int o = f+s+(s*i*2);
    cpl tmp = (w * a[o]);
    aux[i] = a[e] + tmp;
    aux[i+(n/2)] = a[e] - tmp;
    if (invert){
      aux[i] *= half;
      aux[i+(n/2)] *= half;
    }
    w *= wn;
  }
  for (int i=0, ff=f; i<n; ++i, ff+=s) {
    a[ff] = aux[i];
  }
}

int k;
cpl ans[1<<21];
cpl A[1<<21];


void self_convolution(int s){
  bool ac = (1<<s) & k;
  int n = (1<<(11+s));
  if(ac){
    FFT(ans,n);
  }
  FFT(A,n);
  for(int i=0;i<n;i++){
    if(ac){
      ans[i] *= A[i];
    }
    if(s !=9)
      A[i]*=A[i];
  }
  if(s!=9)
    FFT(A,n, true);
  if(ac){
    FFT(ans,n, true);
  }
  for(int i=0;i<n;i++){
    A[i] = cpl(A[i].real() > 0.5?1:0,0);
    if(ac)
      ans[i] = cpl(ans[i].real() > 0.5?1:0,0);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n >> k;
  for(int i=0;i<n;i++){
    int p;
    cin >> p;
    A[p] = cpl(1,0);
  }
  ans[0] = cpl(1,0);
  for(int i=1;i<11;i++){
    DBL(i);
    self_convolution(i-1);
  }
  vector<int> ans2;
  for(int i=0;i<(1<<20);i++){
    if(ans[i].real() > 0.5)
      ans2.push_back(i);
  }
  for(int i=0;i<ans2.size();i++){
    cout<<ans2[i]<<" \n"[i==ans2.size()-1];
  }
  return 0;
}
