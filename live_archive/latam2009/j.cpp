#include <bits/stdc++.h>
/**
* Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=365&page=show_problem&problem=2482
*
*/
using namespace std;

map<char, int> d;

int main(){
	
	d['X'] = 1;
	d['T'] = 2;
	d['S'] = 4;
	d['E'] = 8;
	d['Q'] = 16;
	d['H'] = 32;
	d['W'] = 64;
	
	char c;
	string s;
	while(getline(cin,s)){
		int count=0;
		int good = 0;
		if(s[0]=='*'){
			break;
		}
		istringstream ss(s); 
		while(ss>> c){
			if(c == '/'){
				if(count == 64)
					good++;
				count = 0;
				continue;
			}
			count += d[c];
		}
		cout<<good<<endl;
	}
	
	return 0;
}
