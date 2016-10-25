/*
 * B. Ilya and Queries
 * http://codeforces.com/problemset/problem/313/B
 */
#include <bits/stdc++.h>
using namespace std;


int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s;
  int ac[100011];
  ac[0] = 0;
  cin >> s;
  int n = s.size();
  int k=0;
  for(int i=0;i<n-1;i++){
    k += ((s[i] == s[i+1])?1:0);
    ac[i+1] = k;
  }
  int q,l,r;
  cin >> q;
  while(q--){
    cin>>l>>r;
    cout<<ac[r-1]-ac[l-1]<<"\n";
  }
}
