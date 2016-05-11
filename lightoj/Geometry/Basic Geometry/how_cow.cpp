/**
 * Problem: http://lightoj.com/volume_showproblem.php?problem=1107
 */

#include <bits/stdc++.h>

using namespace std;

#define EPS (1e-9)

int main(){
  int t;
  cin >> t;
  for(int c=1;c<=t;c++){
    int r,l,t,b;
    cin >>l>>b>>r>>t;
    int n;
    int x,y;
    cin >> n;
    cout<<"Case "<<c<<":"<<endl;
    for(int i=0;i<n;i++){
      cin>>x>>y;
      if(x>l && x<r && y>b && y<t){
        cout<<"Yes"<<endl;
      }else{
        cout<<"No"<<endl;
      }
    }
    cout<<endl;
  }

}
