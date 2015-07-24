/**
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&Itemid=99999999&category=567&page=show_problem&problem=4273
 * 
 * For each throw we iterate over the circles adding a point if the 
 * distance to the origin is less that the circle radius. We don't even
 * need binary search, or using lower_bound.
 */

#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": "<<x<<endl;
using namespace std;


int main(){
	int t,n;
	int s;
	double x,y;
	double d;
	int p;
	cin >> t;
	while(t--){
	
		cin >> n;
		s=0;
		for(int i=0;i<n;i++){
			cin >> x>>y;
			d = sqrt(x*x+y*y);
			p=0;
			for(int j=1; j<=10;j++){
				if(d <= 20*j) p++;
			}
			s += p;
		}
		cout << s << endl;
	}
	return 0;
}
