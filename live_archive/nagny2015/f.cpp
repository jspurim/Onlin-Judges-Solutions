/*
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=704&page=show_problem&problem=5386
 */

#include <bits/stdc++.h>

#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;

#else

#define DB(x) 
#define DBL(x) 

#endif

using namespace std;

int v[520][520];
int g[520];
int r[520];
int ag[520][520];
int ar[520][520];

int n;

int main(){
  int p;
  cin >> p;
  while(p--){
    memset(r,0,sizeof r);
  
    memset(g,0,sizeof g);
    int k;
    int d;
    cin >> k;
    cin >> n;
    for(int i=0;i<n;i++){
      cin >> d;
      ag[d][g[d]++] = i;
    } 
    for(int i=0;i<n;i++){
      cin >> d;
      ar[d][r[d]++] = i;
    } 

    memset(v,0,sizeof v);

    queue<pair<int, int> >q;    

    for(int i=0;i<n;i++){
      v[i][i]=true;
      q.emplace(i,i);
    } 

    int t = n;
    while(q.size()){
      pair<int, int> c = q.front();
      q.pop();
      int x = c.first;
      int y = c.second;
      DB(x)DBL(y)
      for(int i=0;i<g[x];i++){
        int xx = ag[x][i];
        for(int j=0;j<g[y];j++){
          int yy = ag[y][j];
          if(!v[xx][yy]){
            v[xx][yy] = true;
            if(!v[yy][xx]){
              t++;
              v[yy][xx]=true;
            }
            t++;
            q.emplace(xx,yy);
          }
        } 
      }
      for(int i=0;i<r[x];i++){
        int xx = ar[x][i];
        for(int j=0;j<r[y];j++){
          int yy = ar[y][j];
          if(!v[xx][yy]){
            //DB(xx)DBL(yy)
            v[xx][yy] = true;
            if(!v[yy][xx]){
              t++;
              v[yy][xx]=true;;
            }
            t++;
            q.emplace(xx,yy);
          }
        } 
      }
    } 
    DBL(t)
    if(t == n*n){
      cout<<k<<" YES"<<endl;
    } else {
      cout<<k<<" NO"<<endl;
    }
    
  }

}
