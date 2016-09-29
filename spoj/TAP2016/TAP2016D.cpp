#include <bits/stdc++.h>
using namespace std;

bool a[50001];
vector<int> ady[50001];
int din[50000];

int ans = 0;

typedef long long ll;
typedef pair<ll,ll> point;

#define X first
#define Y second
#define EPS 1e-6
#define EQ(a,b) (fabs((a)-(b)) < EPS)

#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
#define DBP(p) cerr<<"("<<p.X<<","<<p.Y<<") ";
#define DBPL(p) cerr<<"("<<p.X<<","<<p.Y<<")"<<endl;


double dist(double x, double y, point &p){
  double dx = p.X - x;
  double dy = p.Y - y;
  return sqrt(dx*dx + dy*dy);
}

double distsq(double x, double y, point &p){
  double dx = p.X - x;
  double dy = p.Y - y;
  return dx*dx + dy*dy;
}


double dist(point &p1, point &p2){
  return dist(p1.X, p1.Y, p2);
}


vector<double> protoA;

point npoint(double x, double y){
  return {round(x), round(y)};
}

#define TAU (2*M_PIl)

double nangle(double a){
  if(a < 0) return a+TAU;
  if(a >= TAU) return a-TAU;
  return a;
}

double angle(point &p, point &q){
  return nangle(atan2(q.Y-p.Y, q.X-p.X));
}

double angle(point &p, point &o, point &q){
  return nangle(angle(o,q)-angle(o,p));
}

double inangle(double a){
  if(a>M_PIl){
    return TAU-a;
  }
  return a;
}

bool similar(double a1, double a2, double a3){

  vector<double> angles({a1,a2,a3});
  sort(angles.begin(), angles.end());
  for(int i=0;i<3;i++){
    if(!EQ(angles[i],protoA[i])) return false;
  }
  return true;
}

bool similar(point& p1,point &p2, point& p3){
  return similar(inangle(angle(p1,p2,p3)), inangle(angle(p2,p3,p1)), inangle(angle(p3,p1,p2)));
}

vector<point> intersec(point& p1, double& r1,point &p2, double& r2){
  vector<point> ans;
  //DBP(p1) DBPL(p2)
  //DB(r1) DBL(r2)
  double k=0.5*((r1*r1)-(r2*r2)-(p1.X*p1.X)+(p2.X*p2.X)-(p1.Y*p1.Y)+(p2.Y*p2.Y));
  //DBL(k)
  int dx = p2.X-p1.X;
  int dy = p2.Y-p1.Y;
  //DB(dx) DBL(dy)
  //DB(k) DB(my) DBL(mx)
  if(dy == 0){
    double x = k/dx;
    double a = 1;
    double b = -2*p1.Y;
    double c = -(r1*r1)+(p1.Y*p1.Y)+((x-p1.X)*(x-p1.X));
    double d = sqrt(b*b - 4*a*c);
    double y1 = (-b + d)/(2*a);
    double y2 = (-b - d)/(2*a);
    //DB(k) DB(x) DB(y1) DBL(y2)
    point ans1 = npoint(x, y1);
    point ans2 = npoint(x, y2);
    //DBP(ans1) DBPL(ans2)
    if(distsq(x,y1,ans1) < EPS) ans.push_back(ans1);
    if(distsq(x,y2,ans2) < EPS) ans.push_back(ans2);
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
    point ans1 = npoint(x1, y);
    point ans2 = npoint(x2, y);
    //DBP(ans1) DBPL(ans2)
    if(distsq(x1,y,ans1) < EPS) ans.push_back(ans1);
    if(distsq(x2,y,ans2) < EPS) ans.push_back(ans2);
    return ans;
  }
  //cerr<<"HERE2"<<endl;
  double dy2 = dy*dy;
  double dx2 = dx*dx;
  double a = (dy2/dx2)+1;
  double b = ((2.0*p1.X*dy)/dx) - ((2.0*k*dy)/dx2) - (2*p1.Y);
  double c = ((k*k)/dx2) - (2.0*p1.X*k/dx) + (p1.X*p1.X) +(p1.Y*p1.Y) - (r1*r1);
  double d = sqrt(b*b - 4*a*c);
  //DB(a) DB(b) DBL(c)
  double y1 =  (-b + d)/(2*a);
  double y2 =  (-b - d)/(2*a);
  double x1 = (k - (y1*dy))/dx;
  double x2 = (k - (y2*dy))/dx;
  //DB(x1) DB(y1) DB(x2) DBL(y2)
  point ans1 = npoint(x1, y1);
  point ans2 = npoint(x2, y2);
  //DBP(ans1) DBPL(ans2)
  if(distsq(x1,y1,ans1) < EPS) ans.push_back(ans1);
  if(distsq(x2,y2,ans2) < EPS) ans.push_back(ans2);
  return ans;
}

int m[300][300];

int indexp(const point& p){
  if(p.X < -100 || p.X > 100 || p.Y < -100 || p.X > 100) return -1;
  return m[p.X+150][p.Y+150];
}

vector<double> protoD;

ll thash(int i, int j, int k){
  ll s = i+j+k;
  ll mn = min(i,min(j,k));
  ll mx = max(i,max(k,j));
  s -= mx+mn;
  return mn+mx*1005+s*1005*1005;
}

set<ll> tri;

int main(){
  
  ios_base::sync_with_stdio();
  cin.tie(0);
  int n;
  cin >> n;
  int x, y;
  vector<point> P;
  memset(m,-1,sizeof m);
  for(int i=0;i<n;i++){
    cin >> x >> y;
    P.emplace_back(x,y);
    m[x+150][y+150]=i;
  }
  for(int i=0;i<3;i++){
    protoA.emplace_back(inangle(angle(P[i], P[(i+1)%3], P[(i+2)%3])));
    protoD.emplace_back(dist(P[i], P[(i+1)%3]));
  }
  long long ans = 0;
  sort(protoA.begin(), protoA.end());
  //DB(protoA[0]) DB(protoA[1]) DBL(protoA[2])
  double f[3];
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      double d = dist(P[i], P[j]);
      for(int s=0;s<3;s++){
        f[s] = d/protoD[s];
        bool go=true;
        for(int ss=0;ss<s;ss++){
          if(EQ(f[s],f[ss])){
            go = false;
          }
        }
        if(!go) continue;
        double r1 = protoD[(s+1)%3]*f[s];
        double r2 = protoD[(s+2)%3]*f[s];
        vector<point> candidates = intersec(P[i],r1,P[j],r2);
        for(point p : candidates){
          int k = indexp(p);
          //DBP(P[i]) DBP(P[j]) DBPL(P[k])
          if(k <= j) continue;


          if(similar(P[i],P[j],P[k])){
            //DB(i) DB(j) DBL(k)
            //DB(h)
            ans++;
          }
        }
        if(!EQ(r1,r2)){
          vector<point> candidates = intersec(P[i],r2,P[j],r1);
          for(point p : candidates){
            int k = indexp(p);

            if(k <= j) continue;
            //DBP(P[i]) DBP(P[j]) DBPL(P[k])
            if(similar(P[i],P[j],P[k])){
              //DB(i) DB(j) DBL(k)
              //DB(h)
              ans++;
            }
          }
        }
      }
    }
  }
  cout<<ans<<endl;
}
