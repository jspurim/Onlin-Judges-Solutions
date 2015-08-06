/**
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=4235
 *
 * Notice there is an error in the problem statement. The judge considers 
 * evil wizards to be worth 10 not 11.
 * 
 */

#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": "<<x<<endl;

using namespace std;


int main(){
	long long good [6];
	good[0] = 1;
	good[1] = 2;
	good[2] = 3;
	good[3] = 3;
	good[4] = 4;
	good[5] = 10;
	long long evil [7];
	evil[0] = 1;
	evil[1] = 2;
	evil[2] = 2;
	evil[3] = 2;
	evil[4] = 3;
	evil[5] = 5;
	evil[6] = 10;

	long long n;
	long long g,e;
	long long v;
		cin >> n;
	for(long long i=1;i<=n;i++){
		g=0;
		e=0;
		for(int j=0;j<6;j++){
			cin >> v;
			g += v*good[j];
		}
		
		for(int j=0;j<7;j++){
			cin >> v;
			e += v*evil[j];
		}
		if(e==g){
			cout <<"Battle "<<i<<": No victor on this battle field"<<endl;
		} else if(e>g){
			cout <<"Battle "<<i<<": Evil eradicates all trace of Good"<<endl;
		} else {
			cout <<"Battle "<<i<<": Good triumphs over Evil"<<endl;
		}
	}
	
	
}
