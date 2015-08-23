/**
 * Problem: https://www.urionlinejudge.com.br/judge/en/problems/view/1875
 */
#include <bits/stdc++.h>
#define DB(x) cerr<<#x<<": "<<x<< " ";
#define DBL(x) cerr<<#x<<": "<<x<< endl;

using namespace std;

map<pair<char, char>, int> scores;
map<char, string> name;

int main(){
	scores[make_pair('B','G')] = 1;
	scores[make_pair('B','R')] = 2;
	scores[make_pair('R','B')] = 1;
	scores[make_pair('R','G')] = 2;
	scores[make_pair('G','R')] = 1;
	scores[make_pair('G','B')] = 2;
	name['R'] = "red";
	name['G'] = "green";
	name['B'] = "blue";
	int t;
	cin >> t;
	int r,g,b;
	int n;
	while(t--){
		cin >> n;
		map<char,int> points;
		points['G']=0;
		points['B']=0;
		points['R']=0;
		char w, l;
		char winner = 'R';
		int tie = 3;
		for(int i=0;i<n;i++){
			//DB(tie)
			cin >> w >> l;

			if(points[w] + scores[make_pair(w,l)] > points[winner]){
				winner = w;
				tie = 1;
			}
			else if(points[w] + scores[make_pair(w,l)] == points[winner]){
				winner = w;
				tie++;
			}
			points[w] = points[w] + scores[make_pair(w,l)];
			//DBL(tie)
		}
		
		if(tie == 3){
			cout<<"trempate"<<endl;
			continue;
		}
		if(tie == 2){
			cout<<"empate"<<endl;
			continue;
		}
		cout<<name[winner]<<endl;
	}
	
	return 0;
}
