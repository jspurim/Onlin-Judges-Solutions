/*
* Problem: 
*/
#include <bits/stdc++.h>
using namespace std;

int p[30];
bool v[30];


int main(){

  string s;
  string p;
  
  while(cin>> p>>s){
    int pi = 0;
    bool ok = true;
    for(int i=0;i<s.size()&&ok&&pi<p.size();i++){
      if(s[i] == p[pi]){
        pi++;
        continue;
      } 
      for(int j=pi+1;j<p.size();j++){
        if(s[i] == p[j]){
          ok = false;
          break;
        }  
      }
    }
    if(ok && pi == p.size()){
      cout<<"PASS"<<endl;
    } else {
      cout<<"FAIL"<<endl;
    }
  }

}
