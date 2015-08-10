/*
 * Problem: http://codeforces.com/contest/556/problem/C
 */

#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": "<<x<<endl;
using namespace std;

vector<int> d[100005];


int main(){
	int n,k;
	int a;
	cin>> n>>k;
	for(int i=0;i<k;i++){
		int c;
		cin >> c;
		for(int j=0;j<c;j++){
			
			cin >> a;
			d[i].push_back(a);
			if(a ==1){
				j++;
				int p=a;

				for(;j<c;j++){

					cin >>a;
					if(a!=p+1){
						d[i].push_back(a);
						break;
					}
					p=a;
				}
			}
		}

	}
	int t=k-1;
	for(int i=0;i<k;i++){
		t += (d[i].size()-1)*2;
	}

	cout<<t<<endl;
	return 0;
}
