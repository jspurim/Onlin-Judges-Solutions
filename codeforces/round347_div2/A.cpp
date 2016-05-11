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

  string s1, s2;
  cin>>s1>>s2;
  if(s1==s2){
    cout<<s1<<endl;
  } else {
    cout<<1<<endl;
  }
  return 0;
}
