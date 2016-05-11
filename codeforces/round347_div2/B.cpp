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
  char s[1000];
  char c;
  bool eq = false;
  int t;
  int i=0;
  int p=1;
  int n=0;
  int mn=0;
  int mx=0;
  while(cin >> c){
    if(eq){

    } else {
      if(c == '='){
        break;
      } else if(c == '?'){

      } else {
        s[i]=c;
        i++;
        if(c=='-'){
          n++;
          mx+=-1;
        } else {
          p++;
          mn+=1;
        }
      }
    }
  }
  cin >> t;
  mn -= t*n;
  mx += t*p;
  if(t < mn || t>mx){
    cout<<"Impossible"<<endl;
    return 0;
  } else {
    cout<<"Possible"<<endl;
  }
  int mtr = max(n,p-t);
  int ts = t+mtr;
  int negs[1000];
  for(int j=0;j<n;j++){
    negs[j] = min(t,max(1, mtr/(n-j)+((mtr%(n-j))==0?0:1)));
    mtr -= negs[j];
  }

  int pos[1000];
  for(int j=0;j<p;j++){
    pos[j] = min(max(1, ts/(p-j)+((mtr%(p-j))==0?0:1)),t);
    ts -= pos[j];
  }
  cout<<pos[0];
  int np=1;
  int nn=0;
  for(int j=0;j<p+n-1;j++){
    if(s[j]=='-'){
      cout<<" - "<<negs[nn++];
    } else {
      cout<<" + "<<pos[np++];
    }
  }
  cout<<" = "<<t<<endl;


  return 0;
}
