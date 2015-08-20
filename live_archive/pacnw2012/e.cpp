/**
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=4235

 */

#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": "<<x<<endl;
#define DBP(p) cerr<<"("<<p.x<<","<<p.y<<") angle: " <<p.a<<endl;
#define EPS 0.000000000001

using namespace std;


struct point{
	double x;
	double y;
	double a;
	int set;
	
	bool operator<(const point& rhs) const{
		return (this->a != rhs.a)?this->a<rhs.a:
			(this->x!=rhs.x)?this->x<rhs.x:
			this->y<rhs.y;
	}
};
point pivot;

int main(){

	int n, w, h;
	
	while(cin >> n >> w >> h){
		set<point> tin, tout, tmid, all;
		if(n+w+h == 0) break;
		pivot.x = w/2.0;
		pivot.y = h/2.0;
		int in = 0;
		for(int i=0; i<n;i++){
			point p;
			cin >> p.x >> p.y;
			if(w%2 == 1){
				p.set = p.x > pivot.x;
				p.a = atan2(p.x-pivot.x, p.y-pivot.y);
			} else {
				p.set = p.y > pivot.y;
				p.a = atan2(p.y-pivot.y, p.x-pivot.x);
			}
			if(p.a<0){
				p.a += M_PIl;
			}
			if(p.set){
				tin.insert(p);
			} else {
				tout.insert(p);
			}
			all.insert(p);
		}

		double prev_angle = 0;
		for(auto p: all){
			if(tin.size() + tmid.size() >= (n/2) && tout.size() + tmid.size() >= (n/2)){
				break;
			}
			if(p.a != prev_angle){
				for(auto pm : tmid){
					if(pm.set){
						tout.insert(pm);
					} else {
						tin.insert(pm);
					}
				}
				tmid.clear();
				prev_angle = p.a;
			}
			
			tmid.insert(p);
			if(p.set){
				tin.erase(p);
			} else {
				tout.erase(p);
			}
			
		}
		for(auto p:tin){
			//DBP(p)
			cout <<p.x << " "<<p.y<<endl;
		}
		int c = tin.size();
		//DB(1)
		for(auto p : tmid){
			//DBP(p)
			if(c==n/2) break;
			cout <<p.x << " "<<p.y<<endl;
			c++;
		}
		
		
	}
	
	
}
