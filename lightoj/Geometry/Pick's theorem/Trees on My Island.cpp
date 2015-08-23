#include <bits/stdc++.h>
#define DB(x) cerr << #x << ": "<<x<<" ";
#define DBL(x) cerr << #x << ": "<<x<<endl;
using namespace std;
//This macros are used in the notebook code, copy them!
#define MTPL template<int R, int C, typename T>
#define VTPL template<int N, typename T>
#define forn(i,N) for(int (i)=0;(i)<(N);(i)++)

VTPL
struct Vector{
	T data[N];
	
	T& operator[](int n){
		return data[n];
	}
	
};

//Optional macros. Usage: v.X
#define X data[0]
#define Y data[1]
#define Z data[2]

long long gcd(long long a, long long b){
	if(a%b == 0) return b;
	return gcd(b, a%b);
}

VTPL
T dotProduct(Vector<N,T> v1, Vector<N,T> v2){
	T ans = 0;
	forn(n,N){
		ans += v1[n]*v2[n];
	}
	return ans;
}

/***********************************************************************
 * Polygon
 **********************************************************************/
template<typename T>
struct Polygon{
	vector<Vector<2,T> > points;
	
	Polygon(vector<Vector<2,T> > points){
		this->points = points;
	}
	
	double area(){
		double res, x1, x2, y1, y2;
		res = 0;
		forn(i,points.size()){
			x1 = (double)points[i].X;
			x2 = (double)points[(i+1)%points.size()].X;
			y1 = (double)points[i].Y;
			y2 = (double)points[(i+1)%points.size()].Y;
			res += (x1 *y2 - x2 * y1);
		}
		return fabs(res) /2.0;
	}
	
};

/**********************************************************************
  * Picks theorem
  *********************************************************************/
long long pick(vector<Vector<2,long long> > points){
	int n = points.size();
	double area=0;
	long long b = 0;
	int j;
	Polygon<long long> poly(points);
	area = poly.area();
	for(int i=0;i<n;i++){
		j = (i+1)%n;
		long long dx = abs(points[i].X-points[j].X);
		long long dy = abs(points[i].Y-points[j].Y);
		if(dx == 0){
			b += dy;
		} else if(dy == 0){
			b += dx;
		}else {
			b += gcd(dx,dy);
		}
	}
	long long I = area  - (b/2.0) + 1;
	return I;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	int k = 0;
	while(t--){
		k++;
		int n;
		cin >> n;
		vector<Vector<2,long long> > points;
		forn(i,n){
			Vector<2, long long> p;
			cin >> p.X;
			cin >> p.Y;
			points.push_back(p);
		}
		cout<<"Case "<<k<<": "<<pick(points)<<endl;
	}
	return 0;
}
