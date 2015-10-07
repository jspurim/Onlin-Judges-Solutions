/**
 * Problem: http://codeforces.com/contest/584/problem/D
 */

#include <bits/stdc++.h>
#include <stdint.h>

#define miller_rabin_test isprime

using namespace std;

#include <bits/stdc++.h>

using namespace std;

unsigned long long mod_exp(unsigned long long b, unsigned long long e, unsigned m)
{
  unsigned long long result = 1;
  unsigned long long base = b;

  while (e > 0) {
    if ((e % 2) == 1) 
      result = (result * base) % m;
    e = e >> 1;
    base = (base * base) % m;
	}
  return result;
}

long long mulmod(unsigned long long a,unsigned long long b,unsigned long long c){
    long long x = 0,y=a%c;
    while(b > 0){
		if(b%2 == 1){
			x = (x+y)%c;
		}
		y = (y*2)%c;
		b /= 2;
	}
	return x%c;
}

bool miller_rabin_test(unsigned long long p,unsigned long long iteration){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    unsigned long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        unsigned long long a=(rand()%(p-1))+1,temp=s;
        unsigned long long mod=mod_exp(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}

vector<unsigned long long> P;

bool m[10000000];
int main()
{
  memset(m,1,sizeof m);
  m[0] = m[1] = false;
  for(int i=2;i<sqrt(10000000)+1;i++){
	if(!m[i]) continue;
	for(int j=i+i;j<10000000;j+=i){
		m[j] = false;
	}
  }
  for(int i=2;i<10000000;i++){
	if(m[i])
		P.push_back((unsigned long long)i);
  }
  long long n;
  cin >> n;
  
  for(auto it2 = P.begin(); it2 != P.end();it2++){
	  if(*it2 == n){
		  cout<<1<<endl;
		  cout<<n<<endl;
		  return 0;
	  }
	  if(miller_rabin_test(n-(*it2), 20)){
		 cout<<2<<endl;
		 cout<<n-(*it2)<<" "<<(*it2) <<endl;
		 return 0;
	  }
  }
  auto it = lower_bound(P.begin(),P.end(),n);
  it--;
  if(n-(*it) == 2){
	it--;
  }
  n-= (*it);
  cout<<3<<endl;
  cout<<*it<<" ";
  
  for(auto it2 = P.begin(); it2 != P.end();it2++){
	if(miller_rabin_test(n-(*it2), 100ll)){
		cout<<*it2<<" "<<n-(*it2)<<endl;
		break;
	}
  }
  return 0;
}

