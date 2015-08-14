#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;

using namespace std;

long long C(long long n){
	long long r;
	r = min(n,100ll)*2ll +
		min(max(n-100ll,0ll),10000ll-100ll)*3ll+
		min(max(n-10000ll,0ll), 1000000ll-10000ll)*5ll+
		max(n-1000000ll,0ll)*7;
	return r;
}

long long a, b,s,e,m,k;


long long F(long long n){
	return C(n) - C(k-n); 
}

int main(){

	
	while(cin >> a>> b, a||b){
		
		s=0;e=200000010;
		m=(s+e)/2;
		while(C(m) != a){
			if(C(m) <= a){
				s = m;
			}else {
				e = m;
			}
			m=(s+e)/2;
		}
		
		k=m;
		s=0;
		e=k+1;
		m=(s+e)/2;
		while(F(m) != b){
			if(F(m) <= b){
				s = m;
			}else {
				e = m;
			}
			m=(s+e)/2;
		}
		cout<<C(k-m)<<endl;
	}
}
