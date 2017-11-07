#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct song{
  int s;
  int e;
  ll v;

  song(int s, int e, ll v):s(s), e(e), v(v){}
};

std::vector<song> songs;

#define MN 1
#define MX 10000

#define START 0
#define END 1

ll happiness[2][100005];

void add(int s, int e, ll v){
  happiness[START][s] = v;
  happiness[END][e] = v;
}

ll sum(int array, int s, int e){
  ll ans = 0;
  for(int i=s;i<=e;i++){
    ans+=happiness[array][i];
  }
  return ans;
}

ll outside(int s, int e){
  return sum(END, MN, s-1) + sum(START, e+1, MX);//end before plus start after
}

int main(){
  memset(happiness, 0, sizeof happiness);
  int q;
  cin >> q;
  int t,s,e, id;
  ll v;
  ll total = 0;
  while(q--){
    //cout<<q<<endl;
    cin >> t;
    switch(t){
      case 1:
        cin >> s >> e >> v;
        e--;
        songs.emplace_back(s,e,v);
        total += v;
        add(s,e,v);
        break;
      case 2:
        cin >> id;
        id--;
        total -= songs[id].v;
        add(songs[id].s,songs[id].e,-songs[id].v);
        break;
      case 3:
        cin >>s >> e;
        cout<<total - outside(s,e)<<endl;
    }
  }
}
