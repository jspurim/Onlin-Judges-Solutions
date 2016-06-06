#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
#else
#define DB(x)
#define DBL(x)
#endif
int main(){
  int n,h,k;
  cin >>n >> h;
  int ans =n;
  for(int i=0;i<n;i++){
    cin>>k;
    if(k>h)ans++;
  }
  cout<<ans<<endl;
  
  return 0;
}
