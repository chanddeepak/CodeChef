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
    	string s;
    	cin>>s;
    	vector<int> v(26,0);
    	int j=25;
    	for(int i=0;i<26;i++) {
    		v[i]=j;
    		j--;
    	}
    	int p=n;
    	if(n%2!=0)
    		p=n-1;
    	for(int i=0;i<p-1;i+=2) {
    		swap(s[i],s[i+1]);
    	}
    	for(int i=0;i<n;i++) {
    		//cout<<s[i]<<" ";
    		char q=v[s[i]-'a']+'a';
    		cout<<q;
    	}
    	cout<<"\n";
    }
    return 0;
}