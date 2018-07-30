#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pr pair<int,int>
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
    	long a,b,c,x,y;
    	cin>>a>>b>>c>>x>>y;
    	if(a+b+c<x+y) {
    		cout<<"NO\n";
    		continue;
    	}
    	long s=x+y;
    	if((((a<x&&b<=y)||(a<=x&&b<y))&&(c==s-(a+b)))||
    	(((b<x&&c<=y)||(b<=x&&c<y))&&(a==s-(b+c)))||
    	(((c<x&&a<=y)||(c<=x&&a<y))&&(b==s-(a+c)))||
    	(((b<x&&a<=y)||(b<=x&&a<y))&&(c==s-(b+a)))||
    	(((c<x&&b<=y)||(c<=x&&b<y))&&(a==s-(b+c)))||
    	(((a<x&&c<=y)||(a<=x&&c<y))&&(b==s-(a+c))))
    		cout<<"YES\n";
    	else
    		cout<<"NO\n";
    	
    }
    return 0;
}