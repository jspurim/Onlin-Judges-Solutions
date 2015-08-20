/**
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=622&page=show_problem&problem=4525
 * 
 * The idea here is to represent the state as a 24 bit mask. The mask is
 * divided in 8 sections of 3 bits. We represent each number in the array 
 * as by a number from 0 to 7 acording to their relative order. Once we
 * can represent the state we can apply memoization. The formula for
 * the Expected value for each algorithim involves calculating an infinite
 * convergent series, for this we simply add the first 1000 values which is
 * good enough.
 */

#include <bits/stdc++.h>

#define DB(x) cerr<<#x<<" :" << x<<" ";

#define DBL(x) cerr<<#x<<" :" << x<<endl;
#define INF 1000000000
using namespace std;

double alpha[16], beta[100];

int a[14];

int getm(int m, int p){
	return (m>>(3*p)&7);
}

int setm(int m, int p, int v){
	m &= ~(7<<(3*p));
	return (m | (v<<(3*p)));
}

int swap(int m, int p1, int p2){
	int v1 = getm(m,p1);
	int v2 = getm(m,p2);
	int r = setm(m,p2,v1);
	r = setm(r,p1,v2);
	return r;
}

int n;

bool isSorted(int m){
	for(int i=1;i<n;i++){
		if(getm(m,i)< getm(m,i-1)){
			return false;
		}
	}
	return true;
}

unordered_map<int, double> dc;
unordered_map<int, double> dm;


double M(int m){
	if(dm.find(m) == dm.end()){
		if(isSorted(m)){
			dm[m]=0;
			return 0;
		}
		int u=0;
		double ans = 0;
		double f = 1.0/(n*n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(getm(m,min(i,j))> getm(m,max(i,j))){
					ans += f*(1.0+M(swap(m,i,j)));
				} else {
					u++;
				}
			}
		}
		ans += ((ans+1.0)*beta[u]);
		dm[m] = ans;
	}
	return dm[m];
}

double C(int m){
	if(dc.find(m) == dc.end()){
		if(isSorted(m)){
			dc[m]=0;
			return 0;
		}
		int u=0;
		double ans = 0;
		double f = 1.0/(n-1);
		for(int i=0;i<n-1;i++){
			if(getm(m,i) > getm(m,i+1)){
				ans += f*(1+C(swap(m,i, i+1)));
			}else{
				u++;
			}
		}
		ans += (ans+1.0)*alpha[u];
		dc[m] = ans;
	}
	return dc[m];
}


int main(){
	cout << setprecision(6)<<fixed;
	int t;

	cin >> t;
	set<int> s;
	map<int, int> convert;
	
	
	while(t--){
		dm.clear();
		dc.clear();
		s.clear();
		convert.clear();
		cin >> n;
		double f, fa;
		for(int k=0;k<n;k++){
			f=(double)k/(double)(n-1.0);
			fa=f;
			alpha[k]=0;
			for(int i=0;i<1000;i++){
				alpha[k] +=fa;
				fa *=f;
			}
		}

		for(int k=0;k<(n*n);k++){
			f=(double)k/(double)((n*n));
			fa=f;
			beta[k]=0;
			for(int i=0;i<1000;i++){
				beta[k] +=fa;
				fa *=f;
			}
		}
		for(int i=0;i<n;i++){
			cin >> a[i];
			s.insert(a[i]);
		}
		int p = 0;
		for(auto k: s){
			if(convert.find(k) == convert.end()){
				convert[k] = p;
			}
			p++;
		}
		int m=0;
		for(int i=0;i<n;i++){
			a[i] = convert[a[i]];
			m = setm(m,i,a[i]);
		}


		cout<<"Monty "<<M(m)<<" Carlos "<<C(m)<<endl;
		
	}
	
	
}
