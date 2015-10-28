/*
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3903
 */
#include <bits/stdc++.h>
using namespace std;

#define TAU (2*M_PIl)

#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<(x)<<" ";
#define DBL(x) cerr<<#x<<": "<<(x)<<endl;

#else

#define DB(x)
#define DBL(x)
#endif
int n;

vector<int> ady[1000010];
int gin[1000010];

struct Point {
  double x; 
  double y;
  
  Point(){};
  Point(double x, double y){
    this->x =x;
    this->y=y;
  }
};

bool operator <(const Point& p, const Point& q){
  if(p.y != q.y) return p.y<q.y;
  return p.x<q.x;
}



double norm_angle(double a){
  if(a>= TAU) return a-TAU;
  if(a<0) return a+TAU;
  return a;
}

double angle(Point p, Point q){
  return norm_angle(atan2(q.y-p.y,q.x-p.x));
}

bool bellow(Point p, Point q, Point r){
  if(p.x == q.x){
    return r.x < p.x;
  }
  
  double a = angle(p,q);
  double dx = (r.x-p.x);
  double py = tan(a)*dx+p.y;
   DB(r.x) DB(r.y) DBL(p.y);
  return r.y<py;
}

map<pair<Point, Point>, int > seg; 

int main(){
  int t;
  cin >> t;
  while(t--){
    cin>> n;
    memset(gin,0,sizeof gin);
    seg.clear();
    for(int l=1;l<=n;l++){
      ady[l].clear();
      Point p[3];
      cin>>p[0].x>>p[0].y;
      cin>>p[1].x>>p[1].y;
      cin>>p[2].x>>p[2].y;
      for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
          for(int k=0;k<3;k++){
            if(k == j|| k== i) continue;
            Point P = (p[i]<p[j])?p[i]:p[j];
            Point Q = (p[i]<p[j])?p[j]:p[i];
            if(seg.find(make_pair(P,Q)) == seg.end()){
              seg[make_pair(P,Q)]=l;
            } else {
              int ad = seg[make_pair(P,Q)];
              DB(l) DB(ad)
              if(bellow(P,Q,p[k])){
                DBL(l)
                ady[l].push_back(ad);
                gin[ad]++;
              } else {
                DBL(ad)
                ady[ad].push_back(l);
                gin[l]++;
              }
            }
          }
        }
      }
    }
    vector<int> ans;
    queue<int> q;
    for(int i=1;i<=n;i++){
      if(gin[i] == 0){
        q.push(i);
      }
    }
    while(!q.empty()){
      int cur = q.front();
      ans.push_back(cur);
      q.pop();
      for(int a : ady[cur]){
        gin[a]--;
        if(gin[a] == 0){
          q.push(a);
        }
      }
    }
    for(int i=0;i<n;i++){
      cout<<ans[i]<<" \n"[i==n-1];
    }
  }
}
