#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-6

int n, m;
vector<pair<int, double> > ady[200];
double change[200];
double S[2][200];

//Solve decision problem
bool canDoItStartingWith(double k){
  memset(S, 0, sizeof S);
  int cur = 0;
  int prev = 1;
  S[cur][0] = k;
  for(int i=0;i<=n;i++){    //Do n+1 steps
    swap(prev, cur);
    for(int j=0;j<n;j++){   //For each vertex
      S[cur][j] = S[prev][j];
      for(auto p : ady[j]){ //Try to reach it from every adyacent
        int v = p.first;
        double r = S[prev][v] - p.second;
        S[cur][j] = max(S[cur][j], max(r, r*change[v]/change[j]));
      }
    }
  }
  for(int i=0;i<n;i++){
    // If the n+1 step is better that the n step for some vertex then there
    // is a path of n+1 edges with a gain, so there is a winning cycle.
    if(S[cur][i] - S[prev][i] > EPS){
      return true;
    }
  }
  return false;
}

int main(){
  //Build the graph
  cin >> n >> m;
  for(int i=0;i<n;i++){
    cin >> change[i];
  }
  int a,b;
  double p;
  for(int i=0;i<m;i++){
    cin >> a >> b >> p;
    a--;
    b--;
    ady[a].emplace_back(b, p);
    ady[b].emplace_back(a, p);
  }

  //Binary search the answer
  int s = 0;
  int e = 1000001;
  while(e-s > 1){
    int k = (e+s)/2;
    if(canDoItStartingWith(k)){
      e=k;
    } else {
      s = k;
    }
  }
  if(e < 1000001){
    cout<<e<<endl;
  } else {
    cout<<-1<<endl;
  }
}
