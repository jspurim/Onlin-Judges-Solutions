/**
 * Problem: http://lightoj.com/volume_showproblem.php?problem=1203
 */
 
#include <bits/stdc++.h>
using namespace std;
 
#ifdef DEBUG
#define DB(x) cerr <<#x<<": " <<x<<" ";
#define DBL(x) cerr <<#x<<": " <<x<<endl;
 
#else
 
#define DB(x)
#define DBL(x)
 
#endif
 
struct Vector{
    long long x;
    long long y;
   
    Vector() :x(0),y(0) {};
    Vector(long long x, long long y) : x(x), y(y) {};
};
 
Vector operator-(const Vector& p1, const Vector& p2){
    return Vector(p2.x-p1.x, p2.y-p1.y);
}
 
bool operator ==(const Vector& p1, const Vector& p2){
    return p1.x==p2.x && p1.y==p2.y;
}
 
typedef Vector point;
 
 
bool coordCmp(const Vector& p1, const Vector & p2){
    return (p1.x==p2.x)?(p1.y<p2.y):(p1.x<p2.x);
}
 
bool operator<(const Vector& p1, const Vector & p2){
    return (p1.x==p2.x)?(p1.y<p2.y):(p1.x<p2.x);
}
 
 
double angle(const Vector& p1, const Vector& p2){
    return atan2(p2.y-p1.y, p2.x-p1.x);
}
 
long long cross(point p1, point p2){
    return p1.x*p2.y - p1.y*p2.x;
}
 
bool ccw(point p, point q, point r){
    return cross(p-q, p-r) >= 0;
}
 
double angle(const Vector& p1, const Vector& o, const Vector& p2){
    Vector v = p1-o;
    Vector u = p2-o;
    return acos((v.x*u.x + v.y*u.y) / (sqrt(v.x*v.x+v.y*v.y)*sqrt(u.x*u.x+u.y*u.y)));
}
 
vector<Vector> convex_hull(vector<Vector>& points){
    if(points.size() <= 3){
        return points;
    }
    sort(points.begin(), points.end(), coordCmp);
    vector<Vector> ans(points.size()*2);
    int head=0;
    for(int i=0;i<points.size();i++){
        while(head >= 2 && ccw(ans[head-2], ans[head-1], points[i])){
            head--;
        }
        ans[head++] = points[i];
    }
    int limit = head+1;
    for(int i=points.size()-2;i>=0;i--){
        while(head >= limit && ccw(ans[head-2], ans[head-1], points[i])){
            head--;
        }
        ans[head++] = points[i];
    }
    if(ans[0] == ans[head-1]){
        head--;
    }
    ans.resize(head);
    return ans;
   
}

 
int main(){
    cout<<setprecision(7)<<fixed;
    int t;
    cin >> t;
    int c = 0;
    while(t--){
        c++;
        vector<Vector> points;
        set<Vector> upoints;
        int n;
        cin >> n;
 
        for(int i=0;i<n;i++){
            Vector p;
            cin >> p.x >> p.y;
            upoints.insert(p);
        }
        for(set<point>::iterator it =upoints.begin();it != upoints.end();it++){
            points.push_back(*it);
        }
        if(n<=2){
            cout<<"Case "<<c<<": "<<0<<endl;
            continue;
        }
        vector<Vector> hull = convex_hull(points);
        if(hull.size() <= 2){
            cout<<"Case "<<c<<": "<<0<<endl;
            continue;
        }
        double mn=50000;
        int mod = hull.size();
        for(int i=0;i<hull.size();i++){
            DB(hull[i].x) DBL(hull[i].y);
            mn = min(angle(hull[(i-1+mod)%mod],hull[i],hull[(i+1)%mod]),mn);
        }
        cout<<"Case "<<c<<": "<<(mn*180.0)/M_PIl<<endl;
    }
}
 
