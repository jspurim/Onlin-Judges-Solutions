/*
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=704&page=show_problem&problem=5385
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

int v[520][520];
int g[520];
int r[520];
int ag[520][520];
int ar[520][520];

int n;

int main(){
  int t,p,q;
  cin >> t;
  while(t--){
    int k;
    char d;
    cin >> k>>p>>d>>q;
    long long n=0;
    int r=1;
    while(p+q != 2){
      r++;
      n*=2;
      if(p<q){
        q=q-p;
      } else {
        n++;
        p=p-q;
      }
    }
    n*=2;
    n++;
    long long nn=0;
    while(r--){
      nn*=2;
      nn += n%2;

      n/=2;
    }
    cout<<k<<" "<<nn<<endl;
  }
  return 0;
}
