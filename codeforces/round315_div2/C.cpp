/*
 * Problem: http://codeforces.com/contest/569/problem/C
 * 
 * The answer will not be too big, so we can just compute all primes
 * and all palindromes in the range of the answer. 
 */
#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": "<<x<<endl;
#define DBS cerr<<"i: "<<i<< " primes: "<<primes<<" palindromes: " <<pal<<endl;
#define DBD cerr<<"i: "<<i<< " primes: "<<q*primes<<" palindromes: " <<p*pal<<endl;
using namespace std;

int prm[2000000];

int isPal(int n){
	vector<int> digits;
	int d=0;
	while(n>0){
		digits.push_back(n%10);
		n/=10;
		d++;
	}
	d--;
	for(int i=0;i<=d;i++){
		if(digits[i] != digits[d-i]) return 0;
	}
	return 1;
	
}

int main(){

	memset(prm,255,sizeof prm);
	prm[0]=prm[1]=0;
	for(int i=2; i<10000; i++){
		if(prm[i] != 0){
			prm[i]=1;
			for(int j=2*i;j<2000000;j+=i){
				prm[j]=0;
			}
		}
	}
	long long p, q;
	long long primes, pal;
	cin >> p >> q;
	pal = primes =0;
	int ans = -1;
	for(int i=1;i<2000000;i++){
		
		if(prm[i] != 0){
			primes++;
		}
		if(isPal(i)){
			pal++;
		}
		if((primes*q) <= (pal*p)){
			ans=i;
		}
	}
	cout << ans<<endl;
	return 0;
}
