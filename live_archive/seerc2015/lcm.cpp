/*
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=700&page=show_problem&problem=5188
 */
#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second

typedef unsigned long long ll;

ll gcd (ll a, ll b) {
  if (b == 0ull) return a;
  else return gcd(b, a % b);
}

int main(){
  
  ll a, b;

  while(cin>>a>>b){
    if(a == b){
      cout<<1<<endl;
      continue;
    }
    ll d = (a < b) ? b-a : a-b;
    ll m = a%d;
    ll mlcm=(a+1)/gcd(a+1,b+1)*(b+1);
    ll lcm;
    ll mi=1ull;
    ll x, y;
    ll sq = sqrt(d);
    
    for(ll i=1;i<=sq+2ull;i++){
      if(d % i == 0ull){
        //cerr<<i<<endl;
        ll k = ((i+d)-m)%d;
        if(k == 0) k=i;
        x = a+k;
        y = b+k;
        lcm = x/gcd(x,y)*y;
        if(lcm < mlcm || (lcm == mlcm && k < mi)){
          mlcm = lcm;
          mi = k;
        } 
        ll i2 = d/i;
        //cerr<<i2<<endl;
        k = ((i2+d)-m)%d;
        if(k == 0) k=i2;
        x = a+k;
        y = b+k;
        lcm = x/gcd(x,y)*y;
        if(lcm < mlcm || (lcm == mlcm && k < mi)){
          mlcm = lcm;
          mi = k;
        } 
      }
    }
    cout<<mi<<endl;
  }
}


