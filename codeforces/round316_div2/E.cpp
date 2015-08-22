/**
 * Problem: http://codeforces.com/contest/570/problem/E
 * 
 * Meet in the middle with dynamic programming. It's important to
 * use only O(n^2) memory or you'll get MLE.
 * 
 */

#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": "<<x<<endl;
#define DBP cerr<<"steps: "<<steps << " right: "<< right<< " left: "<<left<<" ("<<r1<<","<<c1<<") ("<<r2<<","<<c2<<")"<<endl;
using namespace std;

int C, R;

char f[510][510];

unsigned long long d[2][500][500];

int main(){
	cin >> R>>C;
	for(int r=0;r<R;r++){
		for(int c=0;c<C;c++){
			cin >> f[r][c];
		}
	}

	int act,old;
	for(int  steps = (R+C-1)/2;steps>=0;steps--){
		act=steps%2;
		old=(steps+1)%2;
		for(int left=0;left<=steps;left++){
			for(int right=0;right<=steps;right++){
				
				int r1=steps-right;
				int c1=right;
				
				int r2=(R-1)-steps+left;
				int c2=(C-1)-left;
				if(r1 <0 || r2 < 0 || r1>=R || r2 >=R
					|| c1 <0 || c2 < 0 || c1>=C || c2 >=C){
					d[act][left][right] = 0ll;
					continue;
				}
				if(r1>r2 || c1>c2){
					d[act][left][right] = 0ll;
					continue;
				}
				if(f[r1][c1] != f[r2][c2]){
					d[act][left][right] = 0ll;
					continue;
				} else if((abs(r1-r2) + abs(c1-c2)) <= 1){

					d[act][left][right] = 1ll;
					continue;
				}
				else if (steps < (R+C-1)/2){
					d[act][left][right] = (d[old][left][right] + d[old][left+1][right+1] + d[old][left+1][right] + d[old][left][right+1]) % 1000000007;
				}
			}
		}
	}
	cout<<d[act][0][0]<<endl;
	
	


	return 0;
}
