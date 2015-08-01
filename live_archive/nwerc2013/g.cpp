/**
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=4639
 * 
 * Very simple geometry.
 * 
 */

#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,c;
	while(cin >> a){
		cin >> b >> c;
		int n,d,g;
		n = a*b;
		d = c-b;
		g = __gcd(n,d);
		n /= g;
		d /= g;
		cout << n << "/"<<d<<endl;
	}
	return 0;
}
