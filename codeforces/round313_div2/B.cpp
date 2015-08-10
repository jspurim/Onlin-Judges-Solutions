/*
 * Problem: http://codeforces.com/contest/560/problem/A
 * 
 * I'm ashamed of what time pressure does to my code sometimes...
 */
#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": "<<x<<endl;
using namespace std;

int main(){
	int a1,a2,a3;
	int b1,b2,b3;
	cin >>a1 >> b1;
	cin >>a2>>b2;
	cin >>a3>>b3;

	int w,h;
	bool ans = false;
	if(a2+a3 <= a1){

		h = max(b2,b3);
		if(h <= b1)
			ans = true;
	} 
	if(a2+a3 <= b1){
		h = max(b2,b3);
		if(h <= a1)
			ans = true;
	} 
	
	if(a2+b3 <= a1){
		h = max(a3,b2);
		if(h <= b1)
			ans = true;
	} 
	if(a2+b3 <= b1){
		h = max(b2,a3);
		if(h <= a1)
			ans = true;
	} 
	//
	if(a3+b2 <= a1){
		h = max(a2,b3);

		if(h <= b1)
			ans = true;
	} 
	if(a3+b2 <= b1){
		h = max(b3,a2);
		if(h <= a1)
			ans = true;
	} 
	//
	
	if(b2+b3 <= a1){
		h = max(a2,a3);
		if(h <= b1)
			ans = true;
	} 
	if(b2+b3 <= b1){
		h = max(a2,a3);
		if(h <= a1)
			ans = true;
	} 
	cout << (ans?"YES":"NO")<<endl;
	return 0;
}
