/*
 * Problem: http://codeforces.com/contest/558/problem/A
 */

#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": "<<x<<endl;
using namespace std;

int pc[110];
int nc[110];

int main(){
	int n, x,a;
	cin>> n;
	int np,nn;
	np = 0;
	nn = 0;
	vector<pair<int,int> > pt;
	vector<pair<int, int> > nt;
	for(int i=0;i<n;i++){
		cin >> x >> a;
		if(x>0){
			pt.push_back(make_pair(x,a));
			np++;
		} else {
			nt.push_back(make_pair(-x,a));
			nn++;
		}
	}
	
	sort(pt.begin(),pt.end());
	sort(nt.begin(),nt.end());
	int mn = min(np,nn);
	
	int s = 0;
	for(int i=0;i<mn;i++){
		s+=nt[i].second+pt[i].second;
	}
	
	
	
	if(np == nn){
		cout<<s<<endl;
	} else if(np<nn){
		cout<<s+nt[mn].second<<endl;
	} else {
		cout<<s+pt[mn].second<<endl;
	}
	return 0;
}

