/*
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=4236
 */

#include <bits/stdc++.h>
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl;
#define tint long long


using namespace std;

bool d[10];

int main(){
	tint n;
	while(cin >> n){
		memset(d,0,sizeof(d));
		tint dc = 0ll;
		while(n %10ll == 0ll){
			if(!d[0]){
				dc++;
				d[0]=true;
			}
			n /= 10ll;
		}
		tint on = n; 
		tint k;
		for(k=1ll; dc <10ll;k++){
			n = on*k;
			while(n >0ll){
				if(!d[n%10]){
					d[n%10] = true;
					dc++;
				}
				n/=10ll;
			}
		}
		cout << k-1<<endl;
	}
	
}
