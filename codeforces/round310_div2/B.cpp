/*
 * Problem: http://codeforces.com/contest/556/problem/B
 */

#include <bits/stdc++.h>
using namespace std;

long long g[10000];

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> g[i];
	}
	int off = g[0];
	for(int i=0;i<n;i++){
		g[i] += off * ((i%2)?1:-1);
		g[i] = (g[i]+n)%n;
		if(g[i] != i){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
