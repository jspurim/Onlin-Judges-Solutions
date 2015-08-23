/**
 * Problem: http://lightoj.com/volume_showproblem.php?problem=1022
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
	cout<<setprecision(2)<<fixed;
	int t;
	cin >> t;
	for(int k =1;k<=t;k++){
		double n;
		cin >> n;
		double ans = (4.0-M_PIl)*(n*n);
		cout<< "Case "<<k<<": "<<ans<<endl;
	}

}
