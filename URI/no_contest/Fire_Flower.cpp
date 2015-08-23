/**
 * Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/1039
 */
#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": "<<x<< " ";
#define DBL(x) cerr<<#x<<": "<<x<< endl;

#define MTPL template<int R, int C, typename T>
#define VTPL template<int N, typename T>
#define forn(i,N) for(int (i)=0;(i)<(N);(i)++)


VTPL
struct Vector{
	T data[N];
	
	T& operator[](int n){
		return data[n];
	}
};


VTPL
T dist(Vector<N,T> v1, Vector<N,T> v2){
	T ans = 0; //Replace for other types.
	forn(n,N)
		ans += (v1[n]-v2[n])*(v1[n]-v2[n]);
	return sqrt(ans);
}

typedef Vector<2,double> Point;

//Optional macros. Usage: v.X
#define X data[0]
#define Y data[1]

using namespace std;


int main(){
	Point c1,c2;
	double r1, r2;
	while(cin >> r1 >> c1.X >> c1.Y >> r2 >> c2.X >> c2.Y){
		if(dist(c1, c2) + r2 > r1){
			cout<<"MORTO"<<endl;
		} else {
			cout<<"RICO"<<endl;
		}
	}
	return 0;
}
