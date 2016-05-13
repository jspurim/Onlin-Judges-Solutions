#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
#else
#define DB(x)
#define DBL(x)
#endif

map<long long, int> l;

vector<pair<pair<int,int>,int > > movies;

long long ml[200010];
long long ms[200010];

int main(){
  int n, m;
  cin >> n;
  long long lang;
  for(int i=0;i<n;i++){
    cin>>lang;
    if(l.count(lang) == 0){
      l[lang] = 1;
    } else {
      l[lang] = l[lang]+1;
    }
  }
  cin>>m;
  for(int i=0;i<m;i++){
    cin >> ml[i];
  }
  for(int i=0;i<m;i++){
    cin >> ms[i];
  }

  for(int i=0;i<m;i++){
    movies.emplace_back(make_pair(-l[ml[i]], -l[ms[i]]), i+1);
  }
  sort(movies.begin(), movies.end());
  cout<<movies.begin()->second<<endl;
  return 0;
}
