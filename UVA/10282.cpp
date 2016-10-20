/*
 * Problem: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1223
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, t, l;
    map<string, string> d;
    
    while(true){
      getline(cin, l);
      stringstream ss(l);
      if(!(ss >> s >> t)) break;
      d[t] = s;
    }
    while(cin >> t){
      if(!d.count(t)) cout<<"eh"<<endl;
      else cout<<d[t]<<endl;
    }
    
}
