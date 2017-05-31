#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
      int n, m;
      cin >> n >> m;
      int u, v;
      for(int j=0;j<m;j++){
        cin >> u >> v;
      }
      cout<<((n%2==0)?"yes":"no")<<endl;
    }
}
