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
    	int n,m;
    	cin>>n>>m;
    	vector<string> s(n);
    	vector<int> row(n,0),col(m,0);
    	for(int i=0;i<n;i++)
    		cin>>s[i];
    	for(int i=0;i<n;i++){
    		for(int j=0;j<m;j++) {
    			if(s[i][j]=='1') {
    				row[i]++;
    				col[j]++;
    			}
    		}
    	}
    	string d;
    	cin>>d;
    	//int l=0,r=0,u=0,e=0;
    	for(int i=0;i<d.size();i++) {
    		if(d[i]=='L') {
    			// l++;
    			// if(r=!0) {
    			// 	r=0;
    			//cout<<d[i]<<" ";
    				for(int i=0;i<n;i++) {
    					int k=0;
    					for(int j=0;j<m;j++) {
    						if(k<row[i]) {
    							if(s[i][j]=='0')
    								col[j]++;
    							s[i][j]='1';
    							k++;
    						} else {
    							if(s[i][j]=='1')
    								col[j]--;
    							s[i][j]='0';
    						}
    					}
    				}
    			//}
    		} else if(d[i]=='R') {
    			// r++;
    			// if(l!=0) {
    			// 	l=0;
    			//cout<<d[i]<<" ";
    				for(int i=n-1;i>=0;i--) {
    					int k=0;
    					for(int j=m-1;j>=0;j--) {
    						if(k<row[i]) {
    							if(s[i][j]=='0')
    								col[j]++;
    							s[i][j]='1';
    							k++;
    						}	else {
    							if(s[i][j]=='1')
    								col[j]--;
    							s[i][j]='0';
    						}
    					}
    				}
    		//	}
    		} else if(d[i]=='D') {
    			// d++;
    			// if(u=!0) {
    			// 	u=0;
    			//cout<<d[i]<<" ";
    				for(int i=m-1;i>=0;i--) {
    					int k=0;
    					for(int j=n-1;j>=0;j--) {
    						if(k<col[i]) {
    							if(s[j][i]=='0')
    								row[j]++;
    							s[j][i]='1';
    							k++;
    						} else {
    							if(s[j][i]=='1')
    								row[j]--;
    							s[j][i]='0';
    						}
    					}
    				}
    		//	}
    	} else if(d[i]=='U') {
    			// u++;
    			// if(=!0) {
    			// 	d=0;
    			//cout<<d[i]<<" ";
    				for(int i=0;i<m;i++) {
    					int k=0;
    					for(int j=0;j<n;j++) {
    						if(k<col[i]) {
    							if(s[j][i]=='0')
    								row[j]++;
    							s[j][i]='1';
    							k++;
    						} else {
    							if(s[j][i]=='1')
    								row[j]--;
    							s[j][i]='0';
    						}
    					}
    				}
    			//}
    		}
    	}
    		for(int i=0;i<n;i++)
    			cout<<s[i]<<"\n";
    	}

    return 0;
}