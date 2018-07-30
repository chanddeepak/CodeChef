#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

//Union Find taken from geeks for geeks

vector<int> in(1000100,0),out(1000100,0);
vector<bool> c(100010,false);

struct subset {
	int parent,rank;
};

long gcd(long a,long b) {
  if(b>a) {
    gcd(b,a);
  }
  if(!b)
    return a; 
  return gcd(b,a%b);
}

int find(vector<subset> &subsets, int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}

void Union(vector<subset> &subsets, int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void cycle(vector<subset> &subsets,int m,int p)
{
	for(int i=p;i<m;i++) {
	    int x = find(subsets,in[i]);
	    int y = find(subsets,out[i]);
	    //cout<<x<<" "<<y<<" ";
	    if (x == y) {
	        c[x]=true;
	        return;
	    }
	    Union(subsets, x, y);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<long> A(n);
    vector<subset> subsets(n);
    for(int i=0;i<n;i++) {
    	cin>>A[i];
    	subsets[i].parent=i;
    	subsets[i].rank=0;
    }
    int j=0,p=0;
    while(m--) {
    	int t;
    	cin>>t;
    	if(t==1) {
    		long x,c;
    		cin>>x>>c;
    		A[x-1]=c;
    	} else if(t==2) {
    		int x,y;
    		cin>>x>>y;
    		in[j]=x-1;
    		out[j]=y-1;
    		j++;
    		cycle(subsets,j,p);
    		j=p;
    	} else {
    		long x,y,v;
    		cin>>x>>y>>v;
    		int a=find(subsets,x-1);
    		int b=find(subsets,y-1);
    		//cout<<a<<" "<<b<<" ";
    		if(a==b&&c[a]==true) {
    			cout<<0<<"\n";
    		}else if(a!=b) {
    			cout<<0<<"\n";
    		} else {
    			long a=v*A[x-1],b=A[y-1];
    			long g=gcd(a,b);
    			if(abs(y-x+1)%2==0)
    				cout<<-a/g<<"/"<<b/g<<"\n";
    			else 
    				cout<<a/g<<"/"<<b/g<<"\n";
    		}
    	}
    }
    return 0;
}
