/*
 * Problem: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2949
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    while(cin >> n >>m){
      if(n + m == 0) break;
      set<int> s;
      int ans=0;
      for(int i=0;i<n;i++){
        cin >> k;
        s.insert(k);
      }
      for(int i=0;i<m;i++){
        cin >> k;
        if(s.count(k)) ans++;
      }
      cout<<ans<<endl;
    }
}
