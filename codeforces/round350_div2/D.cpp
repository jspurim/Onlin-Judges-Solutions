#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
#else
#define DB(x)
#define DBL(x)
#endif


int n;
unsigned long long k;

unsigned long long ing[1000010];
unsigned long long q[1000010];

bool canBake(unsigned long long m){
  unsigned long long diff=0ull;
  for(int i=0;i<n;i++){
    if(ing[i]*m > q[i])
      diff += ing[i]*m-q[i];
    if(diff > k) return false;
  }
  //cerr<<m<<" "<<k<<endl;
  return true;
}

int main(){
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>ing[i];
  }
  for(int i=0;i<n;i++){
    cin>>q[i];
  }
  unsigned long long s,e,m;
  s=0; e=2000000001;
  while(e-s>1){
    m= (e+s)/2;
    if(canBake(m)){
      s=m;
    } else{
      e=m;
    }
  }
  cout<<s<<endl;
  return 0;
}
