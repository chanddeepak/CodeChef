#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
    	string s;
    	cin>>s;
    	long x=0,y=0,n=s.size();
    	vector<vector<long>> freq(n+2,vector<long>(27,0));
    	vector<long> v(27,0);
    	for(int i=0;i<n;i++) {
    		int m=s[i]-'a';
    		v[m]++;
    		for(int j=0;j<26;j++) {
    			if(j<m)
    				y+=v[j];
    			if(j==m) {
    				freq[i+1][j]=freq[i][j]+1;
    				continue;
    			}
    			freq[i+1][j]=freq[i][j];
    		}
    	}
	long ans=1e12;
    	for(int i=0;i<n;i++) {
    		long m=s[i]-'a',p=0;
    		for(int j=0;j<26;j++) {
    			if(j<m){
    				p+=freq[i][j];
    			} else if(j>m) {
    				p+=freq[n][j]-freq[i+1][j];
    			}
    		}
    		for(int j=0;j<26;j++) {
    			if(j==m)
    				continue;
    			long temp=y;
    			x=abs(m-j);
    			long t1=0,t2=0;
    			for(int k=0;k<j;k++) {
    				t1+=freq[i][k];
    			}
    			for(int k=j+1;k<26;k++) {
    				t2+=freq[n][k]-freq[i+1][k];
    			}
    			if(t1+t2+x<p) {
    				temp+=t1+t2+x-p;
    			}
    			if(ans>temp) {
	    			ans=temp;
    			}
    		}
    	}
    	cout<<ans<<"\n";
    }
    return 0;
} 