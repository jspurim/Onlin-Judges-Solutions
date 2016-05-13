#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
#else
#define DB(x)
#define DBL(x)
#endif
int a[200000];
int main(){
  int n;
  long long k;
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  long long s=0;
  long long i=0;
  for(i=0;s+i<k;i++){
    s+=i;
  }
  k-=s;
  //cerr<<k<<" "<<s<<endl;
  cout<<a[k-1]<<endl;
  return 0;
}
