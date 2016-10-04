#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> poly;

ll eval(poly p, ll x){
  ll xx = 1;
  ll ans = 0;
  for(ll c : p){
    ans += c*xx;
    xx*=x;
  }
  return ans;
}

poly derivative(poly p){
  poly pp;
  for(int i=1;i<p.size();i++){
    pp.push_back(p[i]*i);
  }
  return pp;
}

void printPoly(poly p){
  int n = p.size()-1;
  for(auto it = p.rbegin(); it != p.rend(); it++){
    cerr<<*it<<"x^"<<n<<" ";
    n--;
  }
  cerr<<endl;
}

int main(){
  int n;
  while(cin >> n){
    poly P[10];
    P[0].push_back(1);
    int c;
    for(int i=0;i<n;i++){
      cin >> c;
      P[0].push_back(c);
    }
    reverse(P[0].begin(), P[0].end());
    //printPoly(P[0]);
    for(int i=1;i<10;i++){
      P[i] = derivative(P[i-1]);
      //printPoly(P[i]);
    }
    int ans = n;
    for(int r=-10;r<=10;r++){
      int d = 0;
      while(d<n && eval(P[d], r) == 0){
        ans--;
        d++;
      }
    }
    cout<<ans<<endl;
  }
}
