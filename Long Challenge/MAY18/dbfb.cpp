#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
typedef long long ll;
void multiply(long A[2][2],long M[2][2]) {
  long fValue = ((A[0][0]*M[0][0])%MOD+(A[0][1]*M[1][0])%MOD)%MOD;
  long sValue = ((A[0][0]*M[0][1])%MOD+(A[0][1]*M[1][1])%MOD)%MOD;
  long tValue = ((A[1][0]*M[0][0])%MOD+(A[1][1]*M[1][0])%MOD)%MOD;
  long lValue = ((A[1][0]*M[0][1])%MOD+(A[1][1]*M[1][1])%MOD)%MOD;

  A[0][0]=fValue;
  A[0][1]=sValue;
  A[1][0]=tValue;
  A[1][1]=lValue;
}
void power(long A[2][2],int n) {
  if(n==1)
    return;
  power(A,n/2);
  multiply(A,A);
  if(n%2!=0) {
    long F[2][2]={{1,1},{1,0}};
    multiply(A,F);
    return;
  }
}
int fib(int n,long a,long b) {
  if(n==0)
  	return a;
  if(n==1)
	return b;
  long A[2][2]={{1,1},{1,0}};
  power(A,n-1);
  return ((A[0][0]*b)%MOD+(A[0][1]*a)%MOD);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int m,n;
        cin>>m>>n;
        long a[m],s=0,b;
        for(int i=0;i<m;i++) {
            cin>>a[i];
            a[i]=(m*a[i])%MOD;
        }
        for(int i=0;i<m;i++) {
            cin>>b;
            s=(s+b)%MOD;
        }
        long ans=0;
        for(int i=0;i<m;i++) {
        	//cout<<m*a[i]<<" "<<s<<" ";
            long r=fib(n-1,a[i],s);
            //cout<<r<<" ";
            ans=(ans+r)%MOD;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
