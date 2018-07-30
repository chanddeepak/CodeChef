#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pr pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MAX 1000001
typedef long long ll;
vector<int> primes;
void sieve() {
  vector<bool> b(MAX,true);
  b[0]=false;
  b[1]=false;
  for(long i=2;i*i<MAX;i++) {
    if(b[i]==true) {
      for(int j=i;j*i<MAX;j++) {
        b[j*i]=false;
      }
    }
  }
  primes.pb(2);
  for(long i=3;i<MAX;i+=2) {
    if(b[i])
      primes.pb(i);
  }
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;
    cin>>t;
    while(t--) {
    	int n;
    	cin>>n;
    	vector<int> A(n),S(n,0);
    	for(int i=0;i<n;i++) {
    		cin>>A[i];
    		for(int j=0;primes[j]<=A[i];j++) {
    			if(A[i]%primes[j]==0) {
    				S[i]+=primes[j];
    			}
    		}
    	}
    	long ans=0;
    	for(int i=0;i<n;i++) {
    		for(int j=0;j<n;j++) {
    			if(i==j)
    				continue;
    			if(A[j]%A[i]==0&&S[j]%S[i]==0)
    				ans++;
    		}
    	}
    	cout<<ans<<"\n";
    }
    return 0;
}