/**
 * Problem: http://codeforces.com/contest/576/problem/C
 */
#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;

#define mkp make_pair
#define ll long long
#define pll pair<ll,ll>
#define forn(i,N) for(int (i)=0;(i)<(N);(i)++)
#define SECTORS 1000
#define SIZ (1000000/(SECTORS))
using namespace std;
struct Point{
	int x;
	int y;
	int k;
};

bool operator<(const Point& p1, const Point& p2){
	return (p1.y != p2.y)?(p1.y<p2.y):(p1.x<p2.x);
}

vector<Point> points[SECTORS+2];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int x,y;
	int bx,by;
	Point p;
	for(int i=1;i<=n;i++){
		cin >> x >> y;
		bx = x/SIZ;
		//DB(x) DB(SIZ) DBL(bx);
		p.x=x;
		p.y=y*((bx%2)?1:-1);
		p.k=i;
		points[bx].push_back(p);
	}
	vector<int> ans;
	for(int i=0;i<SECTORS+2;i++){
		
		sort(points[i].begin(), points[i].end());
		for(auto k : points[i]){
			//DB(k.k) DBL(i) 
			ans.push_back(k.k);
		}
		
	}
	for(int i=0;i<ans.size();i++){

		cout<<ans[i]<<" \n"[i==ans.size()-1];
	}
	return 0;
}
