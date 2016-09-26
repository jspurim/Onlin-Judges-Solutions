#include <bits/stdc++.h>
using namespace std;

int dr, d, r, rd;

int main(){
  dr=d=r=rd=0;
  int f;
  cin >> f;
  string s;
  for(int i=0;i<f;i++){
    cin >> s;
    bool sd = true;
    bool hd=false;
    for(char c : s){
      if(c == 'D' && sd){
        sd = false;
        hd=true;
      } 
      if(c == 'R' && !sd){
        dr++;
        sd=true;
      }
    }
    bool sr=false;
    for(char c : s){
      if(c == 'R'){ 
        sr=true;
        break;
      } else if (c=='D') {
        break;
      }
    }
    bool ed = !sd && hd;
    if(ed && sr){
      rd++;
    } else if(ed){
      d++;
    } else if(sr){
      r++;
    }
  }
  
  int ans = dr;
  bool hrd = (rd > 0);
  if(hrd){
    ans += rd-1;
    if(d){
      ans++;
      d--;
    }
    if(r){
      ans++;
      r--;
    }
  }
  ans += min(r,d);

  
  cout<<ans<<endl;
}
