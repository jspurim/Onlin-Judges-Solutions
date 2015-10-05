/**
 * Problem: https://www.hackerearth.com/acm-icpc-practice-contest/algorithm/sonya-and-the-graph-with-disappearing-edges-icpc-5/
 */

#include <iostream>
#include <bits/stdc++.h>

#ifdef DEBUG
#define DB(x) cerr <<#x<<": " <<x<<" ";
#define DBL(x) cerr <<#x<<": " <<x<<endl;

#else

#define DB(x) 
#define DBL(x) 

#endif

using namespace std;

struct edge{
	int t;
	int u;
	int v;
};

vector<edge> ady[100001];
vector<edge> E;

struct node{
	int id;
	long long d;
};

bool operator<(const node& n1, const node& n2){
	return (n1.d==n2.d)?(n1.id<n2.id):(n1.d<n2.d);
}


long long d[1000001];
bool v[1000001];
int main()
{
	int n;
	int m, k;
	memset(d,-1,sizeof d);
	memset(v,0,sizeof v);
	cin >> n >> m >> k;
	for(int i=0;i<m;i++){
		edge e;
		cin >>e.u>>e.v;
		e.t = -1;
		E.push_back(e);
	}
	int id; int t;
	for(int i=0;i<k;i++){
		cin >> t >> id;
		E[id-1].t=t;
	}
	for(vector<edge>::iterator it = E.begin(); it!=E.end();it++){
		edge e = (*it);
		ady[it->v].push_back(e);
		edge e2 = e;
		e2.u=e2.v;
		ady[it->u].push_back(e2);
	}
	set<node> q;
	node start;
	start.id=1;
	start.d=0;
	d[1]=0;
	q.insert(start);
	while(!q.empty()){
		set<node>::iterator n = q.begin();
		DBL(n->id);
		DBL(v[n->id])
		if(!v[n->id]){
			v[n->id]=true;
			for(vector<edge>::iterator it=ady[n->id].begin();it!=ady[n->id].end();it++){
				DB("HERE")
				DB(it->u) DBL(it->t)
				DB(n->id)
				DBL(n->d);
				if((it->t != -1) && (it->t <= n->d)){
					continue;
				}
				DB(d[n->id]+1)
				DBL(d[it->u])
				if(d[n->id]+1 < d[it->u] || d[it->u] == -1){
					d[it->u]=d[n->id]+1;
					node a;
					a.id = it->u;
					a.d = d[it->u];
					q.insert(a);
				}
			}
		}
		q.erase(n);	
	}
	cout<<d[n]<<endl;
	
    return 0;
}
