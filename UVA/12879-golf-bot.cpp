#include <complex>
#include <valarray>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <set>

const double TAU = 2*M_PIl;
const int MAX_VAL = 524288;

using namespace std;

typedef complex<double> cplx;
typedef valarray<cplx> Cvector;

// Se asume que x.size() es potencia de dos.
void fft(Cvector& x){
	int n = x.size();
	if(n == 1){
		return; // Caso base
	}
	Cvector even = x[slice(0, n/2, 2)];
	Cvector  odd = x[slice(1, n/2, 2)];
	fft(even);
	fft(odd);
	for(int f=0;f<n/2;f++){
		auto temp = polar(1.0, -(TAU/n)*f)*odd[f];
		x[f] = 	even[f] + temp;
		x[f+n/2] = 	even[f] - temp;
	}
}

void ifft(Cvector& x){
	x = x.apply(conj);
	fft(x);
	x = x.apply(conj);
	x /= x.size();
}

int main(){
  int n, m, k;
  while(cin >> n){

    // Leemos las distancias del robot
    set<int> D;
    Cvector D2(cplx(0,0),MAX_VAL);
    for(int i=0;i<n;i++){
      cin>>k;
      D.insert(k);
      D2[k] = cplx(1,0);
    }

    // Computar la convolucion
    fft(D2);
    for(int i=0; i<MAX_VAL;i++){
      D2[i] = D2[i]*D2[i];
    }
    ifft(D2);

    // Checkeamos cada hoyo
    cin>>m;
    int ans = 0;
    for(int i=0;i<m;i++){
      cin >> k;
      if(D.count(k) || abs(D2[k])>0.9){
        ans++;
      }
    }
    cout<<ans<<endl;
  }
}
