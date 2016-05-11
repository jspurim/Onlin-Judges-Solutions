/**
 * Problem: http://lightoj.com/volume_showproblem.php?problem=1146
 */

#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG

#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
#define DBP(p) cerr<<#p<<": ("<<p.x<<","<<p.y<<")"<<endl;

#else
#define DBP(p)
#define DB(x)
#define DBL(x)

#endif

#define EPS (1e-9)

struct Vector{
  double x;
  double y;

  Vector() :x(0),y(0){};

  Vector(double x, double y) :x(x),y(y){};
};

Vector operator-(const Vector& v2, const Vector& v1){
  return Vector(v2.x-v1.x,v2.y-v1.y);
}

Vector operator+(const Vector& v1, const Vector& v2){
  return Vector(v2.x+v1.x,v2.y+v1.y);
}


Vector operator*(double k, const Vector& v){
  return Vector(k*v.x,k*v.y);
}

double dist_sq(const Vector& v1, const Vector& v2){
  return (v2.x-v1.x)*(v2.x-v1.x) + (v2.y-v1.y)*(v2.y-v1.y);
}

int main(){
  int t;
  cin >> t;
  for(int c=1;c<=t;c++){
    cout<<setprecision(8)<<fixed;
    Vector A,B,C,D;
    cin>> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    Vector deltaAB, deltaCD;
    deltaAB = B-A;
    deltaCD = D-C;
    double s=0;
    double e=1.0;

    DBP(A)
    DBP(B)
    DBP(C)
    DBP(D)

    DBP(deltaAB)
    DBP(deltaCD)
    while(e-s>EPS){
      double lm, rm;

      double third = (e-s)/3.0;
      lm = s+third;
      rm = s+third+third;
      DB(lm) DBL(rm)
      Vector p1 = A+(lm*deltaAB);
      Vector p2 = C+(lm*deltaCD);
      Vector p3 = A+(rm*deltaAB);
      Vector p4 = C+(rm*deltaCD);
      DBP(p1) DBP(p2)
      double dl = (dist_sq(p1,p2));
      double dr = (dist_sq(p3,p4));
      DBL(sqrt(dl))
      DBL(sqrt(dr))
      if(dl > dr){
        s = lm;
      } else {
        e = rm;
      }
    }
    cout<<"Case "<<c<<": "<<sqrt(dist_sq(A+(s*deltaAB),C+(s*deltaCD)))<<endl;
  }

}
