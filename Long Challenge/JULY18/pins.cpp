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
    	int n;
    	cin>>n;
    	int p;
    	if(n%2==0) {
    		p=(n-2)/2+1;
    	} else {
    		p=(n-1)/2+1;
    	}
    	cout<<1<<" "<<1;
    	for(int i=0;i<n-p;i++)
    		cout<<0;
    	cout<<"\n";
    }
    return 0;
}