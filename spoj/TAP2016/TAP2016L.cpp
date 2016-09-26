#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  int a[10005];
  int mx=0;
  int mxi=0;
  for(int i=0;i<m;i++){
    cin>>a[i];
    if(a[i]){
      if(a[i] > mx){
        mx = a[i];
        mxi = i;
      }
    }
  }
  
  if(mxi>0 && mxi<m-1 && a[mxi+1] == a[mxi-1]){
    cout<<"N"<<endl;
    return 0;
  }
  if(mxi > 0){
    int prev = a[0];
    for(int i=1;i<=mxi;i++){
      if(a[i] <=2 || a[i]-prev > 2 || (a[i]-prev) < 1){
        cout<<"N"<<endl;
        cerr<<prev<<" "<<a[i]<<endl;
        return 0;
      }
      prev = a[i];
    }
  }
  //cerr<<mxi<<" "<<a[mxi]<<endl;
  if(mxi < m-1){
    int prev = a[mxi];
    for(int i=mxi+1;i<m;i++){
      if(prev <=2 || prev-a[i] > 2 || prev - a[i] < 1){
        cout<<"N"<<endl;
        cerr<<prev<<" "<<a[i]<<endl; 
        return 0;
      }
      prev = a[i];
    }
  }
  cout<<"S"<<endl;
  return 0;
}
