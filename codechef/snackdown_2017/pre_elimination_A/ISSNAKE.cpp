
#include <bits/stdc++.h>
using namespace std;

string s[2];

bool is(int l, int p){
  return s[l][p] == '#';
}

int main(){
  int T;
  cin >> T;
  for(int t=0;t<T;t++){
    int n;
    cin >> n;
    cin >> s[0];
    cin >> s[1];
    int last=0;
    int first = -1;
    for(int i=0;i<n;i++){
      if(is(0,i) || is(1,i)){
        if(first == -1){
          first =i;
        }
        last = i;
      }
    }
    //cerr<<first<<" "<<last<<endl;
    bool ok = false;
    for(int value=0;value<2 && ok == false;value++){
      //cerr<<value<<endl;
      ok = true;
      int v = value;
      for(int i=first;i<=last;i++){
        //cerr<<"i: "<<i<<" v: "<<v<<endl;
        if(!is(0,i) && !is(1,i)){
          //cerr<<"e1 "<<i<<endl;
          ok = false;
          break;
        }
        else if(is(0, i) && is(1,i)){
          v++;
          v%=2;
        } else if(is(0,i) && v != 0) {
          //cerr<<"e2 "<<i<<endl;
          ok = false;
          break;
        } else if (is(1,i) && v != 1){
          //cerr<<"e3 "<<i<<endl;
          ok = false;
          break;
        }
      }
    }
    cout<<(ok?"yes":"no")<<endl;
  }
}
