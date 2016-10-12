/*
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4942
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct rat{
  ll n;
  ll d;
  
  rat() : n(0), d(1){
  }
  
  rat(ll n, ll d) : n(n), d(d){
    ll g = __gcd(abs(n),d);
    this->n/=g;
    this->d/=g;
  }
  
  void print(){
    if(n == 0) {
      cout<<"not moving"<<endl;
      return;
    }
    cout<<abs(n);
    if(d != 1){
      cout<<"/"<<d;
    }
    cout<<" "<< ((n>0)?"clockwise":"counterclockwise")<<endl;
  }
};

rat operator *(rat &r1, rat& r2){
  return rat(r1.n*r2.n, r1.d*r2.d);
}

rat operator -(rat r){
  return rat(-r.n, r.d);
}



int main(){
  int t;
  cin >> t;
  while(t--){
    vector<int> ady[1001];
    ll  R[1001];
    ll X[1001];
    ll Y[1001];
    rat ans[1001];
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
      cin >> X[i] >> Y[i] >> R[i];
    }
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        ll dx = X[i] - X[j];
        ll dy = Y[i] - Y[j];
        ll r = R[i] + R[j];
        if(r*r == dx*dx +dy*dy){
          ady[i].push_back(j);
          ady[j].push_back(i);
        }
      }
    }
    rat init(1,1);
    ans[0] = init;
    queue<pair<int, int> > q;
    for(int i: ady[0]){
      q.emplace(0,i);
    }
    while(q.size()){
      auto k = q.front();
      q.pop();
      int i = k.second;
      if(ans[i].n != 0) continue;
      int p = k.first;
      rat r(R[p],R[i]);
      ans[i] = -(ans[p] * r);
      for(int j: ady[i]){
        q.emplace(i,j);
      }
    }
    for(int i=0;i<n;i++){
      ans[i].print();
    }
  }
}
