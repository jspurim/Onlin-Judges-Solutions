/*
 * Problem: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=425
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
  multiset<int> ms;
  vector<int> v;
  int n;
  while(cin >> n){
    if(!ms.count(n)){
      v.push_back(n);
    }
    ms.insert(n);
  }
  for(int k : v){
    cout<<k<<" "<<ms.count(k)<<endl;
  }
}
