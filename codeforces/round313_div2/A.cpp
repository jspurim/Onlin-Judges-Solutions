/*
 * Problem: http://codeforces.com/contest/560/problem/A
 */


#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": "<<x<<endl;
using namespace std;

int main(){
	int n;
	cin >> n;
	int k;
	int m= 10000000;
	for(int i=0;i<n;i++){
		cin >> k;
		m = min(m,k);
	}
	cout <<(m==1?-1:1)<<endl;
	

	return 0;
}
