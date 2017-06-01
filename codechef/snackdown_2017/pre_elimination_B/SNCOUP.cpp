#include <bits/stdc++.h>
using namespace std;

bool a[2][100005];
bool b[100005];
int n;

int main(){
  int T;
  cin >> T;
  while(T--){
    cin >> n;
    string s1,s2;
    cin >> s1 >>s2;
    bool horizontalNeeded = false;
    for(int i=0;i<n;i++){
      a[0][i] = s1[i] == '*';
      a[1][i] = s2[i] == '*';
      b[i] = a[0][i] || a[1][i];
      if(a[0][i] && a[1][i]){
        horizontalNeeded = true;
      }
    }

    int ans = 1000000;
    if(!horizontalNeeded){
      ans = 0;
      bool u = false;
      for(int i=0;i<n;i++){
        if(b[i]){
          if(u){
            ans++;
          }
          u = true;
        }
      }
    }
    int i=0;
    int u[2];
    u[0]=u[1]=0;
    int ans2=1;
    for(int i=0;i<n;i++){
      for(int r=0;r<2;r++){
        if(a[r][i] && u[r]){
          u[0]=u[1]=0;
          ans2++;
        }
      }
      u[0] += a[0][i];
      u[1] += a[1][i];
    }
    cout<<min(ans,ans2)<<endl;
  }
}
