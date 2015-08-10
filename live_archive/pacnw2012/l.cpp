/*
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=4246
 */

#include <bits/stdc++.h>
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl;

using namespace std;

map<char, char> code;

int main(){

	code['a'] = 'e';
	code['e'] = 'a';
	code['i'] = 'o';
	code['o'] = 'i';
	code['y'] = 'u';
	code['u'] = 'y';

	code['b'] = 'p';
	code['k'] = 'v';
	code['x'] = 'j';
	code['z'] = 'q';
	code['n'] = 't';
	code['h'] = 's';
	code['d'] = 'r';
	code['c'] = 'l';
	code['w'] = 'm';
	code['g'] = 'f';
	code['p'] = 'b';
	code['v'] = 'k';
	code['j'] = 'x';
	code['q'] = 'z';
	code['t'] = 'n';
	code['s'] = 'h';
	code['r'] = 'd';
	code['l'] = 'c';
	code['m'] = 'w';
	code['f'] = 'g';
	
	string  s;
	while(getline(cin, s)){
		for(int i =0; i< s.size(); i++){
			char c = s[i];
			if(code.find(tolower(c)) == code.end()){
				cout<<c;
			} else {
				if(c == tolower(c)){
					cout <<code[c];
				} else {
					cout<<(char)toupper(code[tolower(c)]);
				}
			}
		}
	}
	
}
