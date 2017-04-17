#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sl,sr;

struct node{
  ll size;
  node *lc, *rc;
  
  node(ll size){
    this->size = size;
    lc = nullptr;
    rc = nullptr;
  }
  
  void insert(){
    if(lc == nullptr){
      lc = new node(size/2 - ((size%2 == 0)?1:0));
      rc = new node(size/2);
      sl = lc->size;
      sr = rc->size;
    } else if (rc->size > lc->size){
      rc->insert();
    } else {
      lc->insert();
    }
    size = max(lc->size, rc->size);
  }  
  
  ~node(){
    if(lc != nullptr){
      delete lc;
      delete rc;
    }
  }
  
}; 

int main(){
  int t;
  cin >> t;
  for(int c=1;c<=t;c++){
    ll n, k;
    cin >> n >> k;
    node root(n);
    for(int i=0;i<k;i++){
      root.insert();
    }
    cout<<"Case #"<<c<<": "<<max(sl,sr)<<" "<<min(sl,sr)<<endl;
  }

}
