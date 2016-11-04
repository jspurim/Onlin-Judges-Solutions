#include <bits/stdc++.h>
using namespace std;



typedef complex<double> cpl;
const cpl I(0,1);
const cpl TAU(2*M_PIl,0);

vector<cpl> a;

vector<cpl> FFT(vector<cpl> x){
  vector<cpl> X;
  int N = x.size();
  if(N == 1){
    X.emplace_back(x[0]);
    return X;
  }
  vector<cpl> e, o;
  for(int i=0;i<N;i++){
    if(i%2){
      o.emplace_back(x[i]);
    } else {
      e.emplace_back(x[i]);
    }
  }
  
  vector<cpl> E = FFT(e);
  vector<cpl> O = FFT(o);
  for(int k=0;k<N/2;k++){
    cpl f = exp(-I*(((1.0*k)/N)*TAU));
    X.push_back(E[k] + f*O[k]);
  }
  for(int k=0;k<N/2;k++){
    cpl f = exp(-I*(((1.0*k)/N)*TAU));
    X.push_back(E[k] - f*O[k]);
  }
  return X;
}

vector<cpl> IFFT(vector<cpl> X){
  int N = X.size();
  vector<cpl> XX;
  for(int i=0;i<N;i++){
    XX.push_back(X[(N-i)%N]);
  }
  vector<cpl> x = FFT(XX);
  for(int i=0;i<N;i++){
    x[i] = x[i]*(1.0/N);
  }
  return x;
}

int main(){
  for(int k : {1,2,5,3,6,2,3,5}){
    a.emplace_back(cpl(k));
  }
  vector<cpl> A = FFT(a);
  vector<cpl> AI = IFFT(A);
  for(int i=0;i<100;i++){
    A = FFT(AI);
    AI = IFFT(A);
  } 
  for(cpl ai : AI){
    cout<<ai.real()<<" ";
  }
  cout<<endl;
}
