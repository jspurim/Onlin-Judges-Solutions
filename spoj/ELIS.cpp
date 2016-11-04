#include <bits/stdc++.h>
using namespace std;

int main(){

  int a[50];
  int l[50];
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
    l[i] = 1;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
      if(a[i] > a[j]){
        l[i] = max(l[i], l[j]+1);
      }
    }
  }
    
  int mx=0;
  for(int i=0;i<n;i++){
    mx = max(mx, l[i]);
  }
  cout<<mx<<endl;
}
