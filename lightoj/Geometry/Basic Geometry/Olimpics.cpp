/*
* Problem: http://lightoj.com/volume_showproblem.php?problem=1056
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define unsigned

#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<(x)<<" ";
#define DBL(x) cerr<<#x<<": "<<(x)<<endl;
#else

#define DB(x)
#define DBL(x)
#endif

int main(){
  int t;
  cin>>t;
  int i=0;
  while(t--){
    cout<<setprecision(9)<<fixed;
    i++;
    double a,b;
    char dummy;
    cin>>a>>dummy>>b;
    double alpha = atan2(b,a);
    double w=2*sin(alpha);
    double l=2*cos(alpha);
    double c=2*alpha;
    double r=(200.0/(l+c));
    cout<<"Case "<<i<<": "<<l*r<<" "<<w*r<<endl;
  }
}
