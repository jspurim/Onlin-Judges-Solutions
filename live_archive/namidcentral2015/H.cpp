/*
* Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5379
*/
#include <bits/stdc++.h>
using namespace std;

bool v[1<<18];
vector<long long> a;
int main(){

  long long n;
  while(cin >>n){
    memset(v, 0, sizeof v);
    a.clear();
    while(n != -1){
      a.push_back(n);
      v[n] = true;
      cin >> n;
    }
    for(long long k : a){
      long long c = 0;
      for(long long i=0ll;i<18ll;i++){
        for(long long j=i;j<18ll;j++){
          long long kk = k ^ ((1<<i)|(1<<j));
          if(kk > k && v[kk]){
            c++;
          }
        }
      }
      cout<<k<<":"<<c<<endl;
    }
  }


  return 0;

}
