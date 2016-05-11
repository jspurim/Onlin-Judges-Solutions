/*
* Problem: http://lightoj.com/volume_showproblem.php?problem=1043
*/
#include <bits/stdc++.h>

using namespace std;

#define EPS (1e-9)

int main(){

  int t;
  cin >> t;
  int c = 0;
  cout<<setprecision(7)<<fixed;
  while(t--){
    c++;
    double ab, bc, ca;
    cin>>ab>>bc>>ca;
    double p;
    cin>>p;
    double s;
    double e;
    s=0;
    double de;
    double q = (ab+bc+ca)/2.0;
    double big_area = q*(q-ab)*(q-bc)*(q-ca);
    double big_h = big_area/bc;
    e=big_h;
    double h1, h2;
    while(e-s>EPS){
      h1=(e+s)/2.0;
      de=bc*h1/big_h;
      h2 = big_h-h1;
      double trapez = ((bc+de)*h2)/2.0;
      double tri = de*h1*0.5;
      if(tri/trapez > p){
        e=h1;
      } else {
        s=h1;
      }
    }
    cout<<"Case "<<c<<": "<<ab*h1/big_h<<endl;
  }
  return 0;
}
