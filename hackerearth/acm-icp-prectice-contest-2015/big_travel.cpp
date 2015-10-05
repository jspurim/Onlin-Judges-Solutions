/**
 * Problem: https://www.hackerearth.com/acm-icpc-practice-contest/algorithm/big-travel-icpc-9/
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	long long x[200005];
	long long y[200005];
	for(int i=0;i<n;i++){
		cin >>x[i]>>y[i];

	}
	sort(x,x+n);
	sort(y,y+n);
	long long acx[200005];
	long long acy[200005];
	acx[0] = x[0];
	acy[0] = y[0];
	for(int i=1;i<n;i++){
		acx[i] = acx[i-1]+x[i];
		acy[i] = acy[i-1]+y[i];
	}
	long long ansx=0;
	long long ansy=0;
	for(int i=0;i<n;i++){

		ansx +=acx[n-1]-acx[i] - (x[i]*(n-i-1));
		ansy +=acy[n-1]-acy[i] - (y[i]*(n-i-1));
		ansx%=1000000007;
		ansy%=1000000007;
	}
	cout<<(ansx+ansy)%1000000007<<endl;
    return 0;
    
}
