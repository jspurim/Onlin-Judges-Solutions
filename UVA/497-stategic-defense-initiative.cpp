/*
 * Problem: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=438
 * 497 Strategic defense initiative
 */
#include <bits/stdc++.h>
using namespace std;

int a[100000];
int l[100000];
int p[100000];

int main(){
  int t;
  cin >> t;
  string s;
  getline(cin, s);
  getline(cin, s);
  while(t--){
    int n = 0;
    while(true){
      getline(cin, s);
      if(s == "") break;
      a[n] = stoi(s);
      n++;
    }
    l[0] = 1;
    p[0] = -1;
    for(int i=1;i<n;i++){
      int mxl = 0;
      int mxi = -1;
      for(int j=0;j<i;j++){
        if(a[j] < a[i] && l[j] > mxl){
          mxl = l[j];
          mxi = j;
        }
      }
      l[i] = mxl+1;
      p[i] = mxi;
    }
    int mxl = 0;
    int mxi = -1;
    for(int i=0;i<n;i++){
      if(l[i] > mxl){
        mxl = l[i];
        mxi = i;
      }
    }
    vector<int> ans;
    while(mxi != -1){
      ans.push_back(mxi);
      mxi = p[mxi];
    }
    cout<<"Max hits: "<<ans.size()<<endl;
    reverse(ans.begin(), ans.end());
    for(int k : ans){
      cout<<a[k]<<endl;
    }
    if(t) cout<<endl;
  }
}
