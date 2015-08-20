/**
 * Problem: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=622&page=show_problem&problem=4534
 */
#include <bits/stdc++.h>
using namespace std;

string L[100];
unordered_set<string> w[100];

int main(){

	int n;
	string s,word;
	cin >> n;
	getline(cin, s);
	for(int i=0;i<n;i++){
		getline(cin, s);
		stringstream ss(s);
		ss>>L[i];
		while(ss>>word){
			for(int j=0;j<word.size();j++){
				word[j] = tolower(word[j]);
			}
			w[i].insert(word);
		}
	}
	
	getline(cin,s);
	while(getline(cin,s)){
		for(int i=0;i<s.size();i++){
			if(s[i] == ',' || s[i] == '.' || s[i] == '!' || s[i] == ';' || s[i] == '?' || s[i] == '(' || s[i] == ')'){
				s[i] = ' ';
			} else {
				s[i] = tolower(s[i]);
			}
		}
		stringstream ss(s);
		bool found = false;
		while(ss>>word && !found){
			
			for(int i=0;i<n;i++){
				if(w[i].find(word) != w[i].end()){
					cout<<L[i]<<endl;
					found = true;
					break;
				}
			}
		}
	}
		
	return 0;

}
