#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

// long fact[10002];
// void factorial() {
// 	fact[0]=1;
// 	fact[1]=1;
// 	for(int i=2;i<=10000;i++) {
// 		fact[i]=(fact[i-1]*i)%(MOD-1);
// 	}
// }

// long modExp(long a,long b) {
// 	long ans=1;
// 	while(b) {
// 		if(b&1) {
// 			ans=(ans*a)%MOD;
// 		}
// 		a=(a*a)%MOD;
// 		b=b/2;
// 	}
// 	return ans;
// }
long ans;

void calCount(vector<long> &a,int s,int cl,int k,int n,vector<long> &data) {
	if(cl==k) {
		for(int i=1;i<k-1;i++) {
			ans=(ans*data[i])%MOD;
		}
		return;
	}
	if(s>=n)
		return;
	data[cl]=a[s];
	calCount(a,s+1,cl+1,k,n,data);
	calCount(a,s+1,cl,k,n,data);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //factorial();
    int t;
    cin>>t;
    while(t--) {
    	int n,k;
    	cin>>n>>k;
    	vector<long> a(n);
    	for(int i=0;i<n;i++)
    		cin>>a[i];
    	sort(a.begin(),a.end());
    	ans=1;
    	// for(int i=0;i<n-k+1;i++) {
    	// 	for(int j=i+1;j<n-1;j++) {
    	// 		long p=n-j-2,q,r=k-3;
    	// 		q=abs(p-k);
    	// 		//cout<<q<<" ";
    	// 		//cout<<fact[p]<<" "<<fact[q]<<" "<<fact[k]<<" ";
    	// 		long temp=fact[p]/(fact[r]*fact[q]);
    	// 		//cout<<modExp(a[j],temp)<<" ";
    	// 		//cout<<temp<<" "<<a[j]<<" ";
    	// 		ans=(ans*modExp(a[j],temp))%MOD;
    	// 	}
    	// }
    	vector<long> data(k);
    	calCount(a,0,0,k,n,data);
    	cout<<ans<<"\n";
    }
    return 0;
}