
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,l,c;
  cin >> n >> l >> c;
  vector<int> a;
  for(int i=0;i<n;i++){
    int k;
    cin >> k;
    a.emplace_back(k);
  }
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  int i=0;
  bool ok = true;
  while(i<n){
    c-=a[i];
    if(c<0) {
      ok = false;
      break;
    }
    i+=l;
  }
  if(ok) {
    cout<<"S"<<endl;
  } else {
    cout<<"N"<<endl;
  }
}
