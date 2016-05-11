/*
* Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&Itemid=99999999&category=706&page=show_problem&problem=5372
*/
#include <bits/stdc++.h>
using namespace std;

int p[30];
bool v[30];



int main(){
  int n; char m; string r;
  while(cin >> n){
    memset(v,0,sizeof v);
    memset(p,0,sizeof p);
    int solved = 0;
    if(n == -1){
      cout << 0<<" "<<0<<endl;
      continue;
    }
    cin >> m >> r;
    int mi = m-'A';
    if(!v[mi]){
      if(r == "right"){
        v[mi] = true;
        solved++;
        p[mi] += n;
      } else {
        p[mi]+=20;
      }
      //cerr << p[mi];
    } 
    while(cin >> n){
      if(n == -1) break;
      cin>>m>>r;
      mi = m - 'A';
      if(!v[mi]){
        if(r == "right"){
          v[mi] = true;
          solved++;
          p[mi] += n;
        } else {
          p[mi]+=20;
        }
      } 
      //cerr << p[mi];
    }
    int tp = 0;
    for(int i=0;i<30;i++){
      if(v[i]){
        tp += p[i];
      }
    }
    cout<<solved<<" "<<tp<<endl;
  }
}
