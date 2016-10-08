/*
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=657&page=show_problem&problem=4898
 */

#include <bits/stdc++.h>
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



const cpl I(0,1);
const double TAU = 2*M_PIl;

cpl aux[1<<19];
cpl half(0.5,0);

void FFT (cpl a[], int n, bool invert=false, int f=0, int s=1) {
  if (n == 1)  return;
  FFT(a, n/2,invert, f,s*2);   //E
  FFT(a,n/2,invert,f+s,s*2);   //O
 
  double ang = (TAU/n) * (invert ? -1 : 1);
  cpl w(1,0),  wn (cos(ang), sin(ang));
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
  for (int i=0; i<n; ++i) {
    a[f+(i*s)] = aux[i];
  }
}
/*
void convolution(vector<int>& a, vector<int>& b, vector<int>& c){
  vector<cpl> A(a.begin(), a.end());
  vector<cpl> B(b.begin(), b.end());
  int m = max(A.size(),B.size());
  int n=1;
  while(n<m) n <<=1;
  n <<=1;
  A.resize(n); B.resize(n); c.resize(n);
  FFT(A); FFT(B);
  for(int i=0;i<n;i++){
    A[i]*=B[i];
  }
  FFT(A, true);
  for(int i=0;i<n;i++){
    c[i] = (int)(A[i].real() +0.5);
  }
}*/


int main(){
  int n, m;
  cpl *a;
  while(cin >> n){
    a = new cpl[1<<19];
    vector<int> D, M;
    int mx=0;
    for(int i=0;i<n;i++){
      int d;
      cin >> d;
      D.push_back(d);
      mx = max(mx,d);
    }
    cin >> m;
    for(int i=0;i<m;i++){
      int d;
      cin >> d; 
      M.push_back(d);
      mx = max(mx,d);
    }

    a[0] = cpl(1,0);
    for(int d: D){
      a[d] = cpl(1,0);
    }
    int s = 1;
    while(s < mx+1){
      s*=2;
    }
    s*=2;
    FFT(a,s);
    for(int i=0;i<s;i++){
      a[i]*=a[i];
    }
    FFT(a,s,true);
    
    int ans = 0;
    for(int d : M){
      if(a[d].real() > 0.9) ans++;
    }
    cout<<ans<<endl;
  }
  return 0;
}
