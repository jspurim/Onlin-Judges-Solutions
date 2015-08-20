/**
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=622&page=show_problem&problem=4534
 */
#include <bits/stdc++.h>
using namespace std;

#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;

int Y[40];

long long d[40][40][10][10];

long long W(int l, int r, int cl, int cr){
	if(d[l][r][cl][cr] == -1){
		long long ans;
		if(r==l){
			if((Y[r] + cr) % 2 == 1){
				d[l][r][cl][cr] = 0;
			} else {
				//DB(l)DB(r)DB(cl)DBL(cr)
				d[l][r][cl][cr] = 1;
			}
		} else if (l==r+1){
			ans = 0;
			set<pair<int, int> > u[2];
			for(int x=(r==0)?1:0;x<=9;x++){
				int z = Y[r]-cr-x;
				if(z<0)
					z+=10;
				int c = (z+x+cr)/10;
				if((z+x+c)%10 == Y[l] && (z+x+c)/10 == cl){
					//DB(x)DBL(z);
					ans++;
				}
			}
			d[l][r][cl][cr] = ans;
		} else{
			
			ans = 0;
			for(int x=(r==0)?1:0;x<=9;x++){
				int z = Y[r]-cr-x;
				if(z<0)
					z+=10;

				int c = (z+x+cr)/10;
				int ncl = ((Y[l] -((x+z)%10))+10)%10;
				//DB(x) DB(z) DB(Y[l]) DB(c) DB(ncl) DBL(W(l-1,r+1,ncl,c))
				//DBL(((ncl == 0 || ncl == 1 ) && (x+z+c)/10 == cl))
				if((ncl == 0 || ncl == 1 ) && (x+z+ncl)/10 == cl){
					//DB(l) DB(r) DB(ncl) DBL(c)
					ans += W(l-1,r+1,ncl,c);
				}
			}
			d[l][r][cl][cr] = ans;
		}
		//DB(l) DB(r) DB(cl) DB(cr) DBL(d[l][r][cl][cr])
	} 
	return d[l][r][cl][cr];

}

int main(){

	int t;
	cin >> t;
	long long n;
	while(t--){
		memset(d,-1,sizeof d);
		cin >> n;
		long long bk = n;
		int p = 0;
		while(n>0){
			Y[p] = n%10;
			p++;
			n/=10;
		}
		p--;
		//DB(p)
		long long ans = W(p,0,0,0);
		if(Y[p] == 1){
			ans += (W(p-1,0,1,0));
		}
		cout<<ans<<endl;
	}
		
	return 0;

}
