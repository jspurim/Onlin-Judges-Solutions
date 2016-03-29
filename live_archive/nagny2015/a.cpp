/*
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=704&page=show_problem&problem=5381
 */

#include <bits/stdc++.h>


#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;

#else

#define DB(x) 
#define DBL(x) 

#endif

using namespace std;

long long a[10010];
long long o[10010];
long long e[10010];
int main(){
  a[0] = o[0] = 0;
  e[0]= 0;
  for(int i=1;i<10010;i++){
    a[i] = a[i-1]+i;
    o[i] = o[i-1]+((2*i)-1);
    e[i] = e[i-1]+(2*i);
  }
  int t;
  cin >>t;
  while(t--){
    int k;
    cin >> k;
    int q;
    cin >> q;
    cout<<k<<" "<<a[q]<<" "<<o[q]<<" "<<e[q]<<endl;
  }
  return 0;
}
