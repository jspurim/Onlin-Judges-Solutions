#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define DB(x) cerr<<#x<<": "<<x<<" ";
#define DBL(x) cerr<<#x<<": "<<x<<endl;
#else
#define DB(x)
#define DBL(x)
#endif

#define R 0
#define L 1

#define pair asdasdagsdfds
#define union sadasdafsdggdqf

int pair[500010];
bool del[500010];

int p[2][500010];

int find(int d, int i){
  if(d == R){
    i = max(i,pair[i]);
  } else{
    i = min(i,pair[i]);
  }
  if(i==p[d][i])
    return i;
  p[d][i] = find(d, find(d, p[d][i]));
  return p[d][i];
}

void union(int d, int i, int j){
  if(d == R){
    i = max(i,pair[i]);
    j= max(j,pair[j]);
  } else{
    i = min(i,pair[i]);
    j= min(j,pair[j]);
  }

  int ri = find(d, i);
  int rj = find(d, j);
  int rm = min(ri, rj);
  int rM = max(ri, rj);
  if(d == R){
    p[d][rm]=rM;
  } else{
    p[d][rM]=rm;
  }
}

string s;

int repos(int cursor){
  int t = find(R, cursor);
  t++;
  if(t == s.size())
    t = find(L, cursor)-1;
  return t;
}

int main(){
  memset(del, 0, sizeof del);
  int cursor;
  int dummy;
  cin >> dummy >> dummy>>cursor;
  cursor--;
  cin>>s;
  stack<int> st;
  for(int i=0;i<s.size();i++){
    if(s[i]=='('){
      st.push(i);
    } else {
      pair[i] = st.top();
      st.pop();
      pair[pair[i]]=i;
    }
  }

  for(int i=0;i<s.size();i++){
    p[0][i]=i;
    p[1][i]=i;
  }


  string cmd;
  cin>>cmd;
  for(char c: cmd){
    /*for(int i=0;i<s.size();i++){
      if(i==cursor)cout<<"<";
      if(!del[i]) cout<<s[i];
      if(i==cursor)cout<<">";
    }
    cout<<endl;*/
    if(c == 'R') {
      //cerr<<"R"<<endl;
      cursor++;
      if(del[cursor]){
        cursor = repos(cursor);
      }
    }else if(c == 'L') {
      //cerr<<"L"<<endl;
      cursor--;
      if(del[cursor]){
        cursor = max(0,find(L, cursor)-1);
      }
    }
    else{
      //cerr<<"D"<<endl;
      del[cursor] = true;
      del[pair[cursor]] = true;
      int mn = min(cursor, pair[cursor]);
      int mx = max(cursor, pair[cursor]);
      if(mn > 0 && del[mn-1]){
        union(R, mn,mn-1);
        union(L, mn,mn-1);
      }
      if(mx < s.size() && del[mx+1]){
        union(R, mx,mx+1);
        union(L, mx,mx+1);
      }
      cursor = repos(cursor);
    }
  }

  for(int i=0;i<s.size();i++){
    if(del[i]) i = pair[i];
    if(!del[i]) cout<<s[i];
  }
  cout<<endl;

  return 0;
}
