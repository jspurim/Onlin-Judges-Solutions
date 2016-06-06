#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
#else
#define DB(x)
#define DBL(x)
#endif

long long a[100100];
long long h;
long long n;
long long k;
long long m;

int main(){
  cin>>n>>h>>k;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  long long c = 0;
  long long t=0;
  long long ans = 0;
  while(c<n){
    //cerr<<"T: "<<t<<endl;
    long long s=-1;
    long long e=1000000001;
    while(e-s>1){
      m=(s+e)/2;
      //cerr<<m<<endl;
      long long tt = max(0ll, t-(m*k));
      if(h-tt>=a[c]){
        e=m;
      } else {
        s=m;
      }
    }
    ans += e;
    t -= (k*e);
    t = max(t,0ll);
    //cerr<<"---- "<<e<<endl;
    while(t+a[c]<=h && c<n){
      //cerr<<"t: "<<t<<endl;
      t+= a[c];
      //cerr<<a[c]<<endl;
      c++;
    }
  }
  ans += t/k;
  ans += (t%k == 0)?0:1;
  cout<<ans<<endl;
  return 0;
}
