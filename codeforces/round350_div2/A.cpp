#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
#else
#define DB(x)
#define DBL(x)
#endif
int main(){
  int n;
  cin >> n;
  int d = n/7;
  int mn = 2*d;
  int mx = mn;
  int m = n%7;
  if(m == 6) mn++;
  mx += min(2, m);
  cout<<mn<<" "<<mx<<endl;
  return 0;
}
