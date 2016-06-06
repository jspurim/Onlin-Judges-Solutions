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
  string s;
  cin >> s;
  int ones=0;
  for(char c : s){
    int k;
    if(c == '-') k = 62;
    if(c =='_') k = 63;
    if(c >= '0' && c <= '9') k = c-'0';
    if(c >= 'A' && c <= 'Z') k = c-'A'+10;
    if(c >= 'a' && c <= 'z') k = c-'a'+36;
    while(k>0){
      ones += k%2;
      k/=2;
    }
  }
  int zeros = (6*s.size())-ones;
  //cerr<<ones<<" "<<zeros<<endl;
  long long ans = 1;
  for(int i=0;i<zeros;i++){
    ans *=3;
    ans %= 1000000007;
  }
  cout<<ans;
  
  return 0;
}
