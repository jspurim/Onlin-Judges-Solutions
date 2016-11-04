#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<double,double> point;

#define X first
#define Y second
#define EPS 1e-6
#define EQ(a,b) (fabs((a)-(b)) < EPS)

#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
#define DBP(p) cerr<<"("<<p.X<<","<<p.Y<<") ";
#define DBPL(p) cerr<<"("<<p.X<<","<<p.Y<<")"<<endl;

double dist(point &p1, point &p2){
  return sqrt((p1.X-p2.X)*(p1.X-p2.X)+(p1.Y-p2.Y)*(p1.Y-p2.Y));
}

bool doCirclesIntersec(point p1, double r1,point p2, double r2){
  double d = dist(p1,p2);
  if(min(r1,r2)+d < max(r1,r2) || d > r1+r2){
    return false;
  }
  return true;
}

vector<point> circlesIntersection(point p1, double r1,point p2, double r2){
  /*
   * NOTA: DEVUELVE DOS VECES EL MISMO PUNTO PARA CIRCUNFERENCIAS TANGENTES!!!
   */
  vector<point> ans;
  if(!doCirclesIntersec(p1,r1,p2,r2)) return ans;
  double k=0.5*((r1*r1)-(r2*r2)-(p1.X*p1.X)+(p2.X*p2.X)-(p1.Y*p1.Y)+(p2.Y*p2.Y));
  int dx = p2.X-p1.X;
  int dy = p2.Y-p1.Y;
  if(dy == 0){
    double x = k/dx;
    double a = 1;
    double b = -2*p1.Y;
    double c = -(r1*r1)+(p1.Y*p1.Y)+((x-p1.X)*(x-p1.X));
    double d = sqrt(b*b - 4*a*c);
    double y1 = (-b + d)/(2*a);
    double y2 = (-b - d)/(2*a);
    point ans1 = {x, y1};
    point ans2 = {x, y2};
    ans.push_back(ans1);
    ans.push_back(ans2);
    return ans;
  } 
  if(dx == 0){
    double y = k/dy;
    double a = 1;
    double b = -2*p1.X;
    double c = -(r1*r1)+(p1.X*p1.X)+((y-p1.Y)*(y-p1.Y));
    double d = sqrt(b*b - 4*a*c);
    double x1 = (-b + d)/(2*a);
    double x2 = (-b - d)/(2*a);
    point ans1 = {x1, y};
    point ans2 = {x2, y};
    ans.push_back(ans1);
    ans.push_back(ans2);
    return ans;
  }
  double dy2 = dy*dy;
  double dx2 = dx*dx;
  double a = (dy2/dx2)+1;
  double b = ((2.0*p1.X*dy)/dx) - ((2.0*k*dy)/dx2) - (2*p1.Y);
  double c = ((k*k)/dx2) - (2.0*p1.X*k/dx) + (p1.X*p1.X) +(p1.Y*p1.Y) - (r1*r1);
  double d = sqrt(b*b - 4*a*c);
  double y1 =  (-b + d)/(2*a);
  double y2 =  (-b - d)/(2*a);
  double x1 = (k - (y1*dy))/dx;
  double x2 = (k - (y2*dy))/dx;
  point ans1 = {x1, y1};
  point ans2 = {x2, y2};
  ans.push_back(ans1);
  ans.push_back(ans2);
  return ans;
}



int main(){

  double x1,y1,r1,x2,y2,r2;
  while(cin>> x1>>y1>>r1>>x2>>y2>>r2){
    for(point p : circlesIntersection({x1,y1},r1,{x2,y2},r2)){
      DBP(p);
    }
    cerr<<endl;
  }
}
