#include <bits/stdc++.h>
using namespace std;

char flip(char x){
  if(x=='-')
    return '+';
  return '-';
}

int main(){
  int t;
  string s;
  int k;
  cin >> t;
  int l;
  for(int c=1; c<=t;c++){
    cin >> s;
    cin >> k;
    l = s.size();
    bool ok = true;
    int ans=0;
    for(int i=0;i<l;i++){
      if(s[i] == '-'){
        if(i+k > l){
          ok = false;
          break;
        }
        for(int j=0;j<k;j++){
          s[i+j] = flip(s[i+j]);
        }
        ans++;
      }
    }
    if(ok)
      cout<<"Case #"<<c<<": "<<ans<<endl;
    else
      cout<<"Case #"<<c<<": IMPOSSIBLE"<<endl;
  }

}
