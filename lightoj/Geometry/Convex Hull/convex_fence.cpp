/**
 * Problem: http://lightoj.com/volume_showproblem.php?problem=1203
 */

#include <bits/stdc++.h>

#ifdef DEBUG
#define DB(x) cerr <<#x<<": " <<x<<" ";
#define DBL(x) cerr <<#x<<": " <<x<<endl;

#else

#define DB(x) 
#define DBL(x) 

#endif

#define EPS 1e-9

#define point_i point

#define EQ(x,y) (fabs((x)-(y))<EPS)
using namespace std;

struct point{
	long long x;
	long long y;
	
	point() :x(0),y(0){};
	
	point(int x, int y){
		this->x = x;
		this->y = y;
	}
};

point operator-(const point& p1, const point& p2){
	return point(p1.x-p2.x, p1.y-p2.y);
}

bool operator==(const point&p1, const point& p2){
	return p1.x==p2.x && p1.y==p2.y;
}
long long cross(point p1, point p2){
	return p1.x*p2.y - p1.y*p2.x;
}

bool ccw(point p, point q, point r){
	return cross(p-q, p-r) > 0;
}

long long cross (point_i &o, point_i &a, point_i &b) {
    return (a.x-o.x) * (b.y-o.y) - (a.y-o.y) * (b.x-o.x); }

double angle(const point& p1, const point& p2){
	double a = atan2(p2.y-p1.y, p2.x-p1.x);
	DB(p1.x) DBL(p1.y)
	DB(p2.x) DBL(p2.y)
	if(a <0)
		a+=2*M_PIl;
	DBL(a)
	return a;
}

point perpendicular_left(const point& v){
	return point(-v.y,v.x);
}

point perpendicular_right(const point& v){
	return point(v.y,-v.x);
}


double angle(const point& p1, const point& o, const point& p2){
	point v = p1-o;
	point u = p2-o;
	
	DB(v.x) DBL(v.y)
	
	DB(u.x) DBL(u.y)
	
	v = perpendicular_right(v);
	u = perpendicular_left(u);
	DB(v.x) DBL(v.y)
	
	DB(u.x) DBL(u.y)
	return acos((u.x*v.x + u.y*v.y) / (sqrt(u.x*u.x+u.y*u.y)*sqrt(v.x*v.x+v.y*v.y)));
}

point pivot(0,0);

bool compByCoor(const point& p1, const point& p2){
	return (p1.y == p2.y)?(p1.x>p2.x):(p1.y<p2.y);
}
double dist(const point& p1, const point& p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

bool compByAngle(const point& p1, const point& p2){
	double a1 = angle(pivot, p1);
	double a2 = angle(pivot, p2);
	double d1 = dist(pivot, p1);
	double d2 = dist(pivot, p2);
	return (a1 == a2)?(d1<d1):(a1<a2);
}
struct cmp {
    bool operator()(const point_i &a, const point_i &b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x; }
}myCmp;

vector<point_i> convex_hull (vector<point_i> &pol) {
    int i, t, n = (int)pol.size(), k = 0;
    if (n <= 3) return pol;
    vector<point_i> ans(2*n);
    sort(pol.begin(), pol.end(), myCmp);
    for (i=0; i<n; i++) {
        while (k >= 2 && cross(ans[k-2], ans[k-1], pol[i]) <= 0) k--;
        ans[k++] = pol[i];
    }
    for (i=n-2, t=k+1; i>=0; i--) {
        while (k >= t && cross(ans[k-2], ans[k-1], pol[i]) <= 0) k--;
        ans[k++] = pol[i];
    }
    if (ans[0] == ans[k-1]) k--;
    ans.resize(k);
    return ans;
}




int main(){
	cout<<setprecision(9)<<fixed;
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	int c = 0;
	while(t--){
		c++;
		int n;
		double d;
		cin >> n >> d;
		vector<point> points;
		int x, y;
		for(int i=0;i<n;i++){
			cin >> x >> y;
			points.push_back(point(x,y));
		}
		
		if(n==1){
			cout<<"Case "<<c<<": "<<M_PIl*d*2<<endl;
			continue;
		}
		
		
		vector<point_i> hull = convex_hull(points);
		if(hull.size() == 2){
			cout<<"Case "<<c<<": "<<(M_PIl*d*2)+(2*dist(hull[0],hull[1]))<<endl;
			continue;
		}
		double ans = 0;
		int mod = hull.size();
		for(int i=0;i<hull.size();i++){
			DB(hull[i].x) DBL(hull[i].y);
			ans += dist(hull[i], hull[(i+1)%mod]);
			double a = angle(hull[(i+mod-1)%mod],hull[i], hull[(i+mod+1)%mod]);
			DBL(a)
			ans += a*d;
		}
		cout<<"Case "<<c<<": "<<ans<<endl;
		
	}
	
	return 0;
}
