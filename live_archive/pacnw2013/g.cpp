/**
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=622&page=show_problem&problem=4529
 */
#include <bits/stdc++.h>
using namespace std;

long long F[100];

int main(){
	
	F[0]=1;
	F[1]=1;
	F[2]=2;
	F[3]=4;
	for(int i=4;i<100;i++){
		F[i] = 0;
		for(int j=1;j<=4;j++){
			F[i] += F[i-j];
		} 
	}
	
	int t;
	int n;
	cin >> t;
	while(t--){
		cin >> n;
		cout<<F[n]<<endl;
	}
	return 0;
}
