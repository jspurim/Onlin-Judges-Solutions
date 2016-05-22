/*
* Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&Itemid=99999999&category=706&page=show_problem&problem=5377
*/
#include <bits/stdc++.h>
using namespace std;


int main(){

  int n;
  while(cin >> n){
    vector<string> ss, sss, ssr;
    string s;
    for(int i=0;i<n;i++){
      cin >> s;
      ss.push_back(s);
      sss.push_back(s);
      ssr.push_back(s);
    }
    
    sort(sss.begin(),sss.end());
    sort(ssr.rbegin(),ssr.rend());
    bool sorted = true;
    bool rsorted = true;
    for(int i=0;i<n;i++){
      if(ss[i] != sss[i]){
        sorted = false;
        break;
      }
    }
    for(int i=0;i<n;i++){
      if(ss[i] != ssr[i]){
        rsorted = false;
      }
    }
    //cout<<sorted<<" "<<rsorted<<endl;
    if(sorted){
      cout<<"INCREASING"<<endl;
    } else if(rsorted){
      cout<<"DECREASING"<<endl;
    } else {
      cout<<"NEITHER"<<endl;
    }
  }

}
