#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
typedef long long ll;
map<int,int> m;
int ans;
int binary_search(int* a, vector<int> &b,int n,int x,int max,int min) {
    int low, high, mid,f=0,g=0,l=0,e=0,o=0;
    low = 1;
    high = n;
    ans=0;
    vector< pair<int,int> > v;
    while (low <= high) {
        mid = (low + high) / 2;
        if(x==max&&m[x]<mid) {
            f=1;
            break;
        }
        if(x==min&&m[x]>mid) {
            f=1;
            break;
        }
        if (a[mid] == x)
            break;
        else if (a[mid] < x) {
            l++;
            if(mid>m[x]) {
            	o++;
                v.pb(mp(a[mid],0));
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        else if(a[mid]>x) {
            g++;
            if(mid<m[x]) {
            	e++;
                v.pb(mp(a[mid],1));
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
    }
    //cout<<v.size()<<" ";
    if(f==1||v.size()==0)
        return mid;
    else {
        sort(v.begin(),v.end());
        int it=upper_bound(b.begin(),b.end(),x)-b.begin();
        int gi=n-it,li=n-gi-1,p=0;
        gi-=g;
        li-=l;
        //cout<<gi<<" "<<li<<" "<<v.size()<<" ";
        bool b[20]={false};
        for(int i=0;i<v.size();i++) {
            if(b[i]==false) {
                int fi=v[i].second;
                for(int j=i+1;j<v.size();j++) {
                    if(fi!=v[j].second&&b[j]==false) {
                        p++;
                        b[i]=true;
                        b[j]=true;
                        o--;
                        e--;
                        break;
                    }
                }
            }
        }
       // cout<<o<<" "<<e<<" ";
        int r=v.size()-2*p;
        if(r==0) {
        	ans=p;
	return mid;
        }
	else {
		if(e<=li&&o<=gi) {
			ans=p+o+e;
			return mid;
		}
	}
        }
        return -1;

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--) {
		int n,q;
		cin>>n>>q;
		int a[n+1],max=0,min=INT_MAX;
		vector<int> b(n);
		b[0]=0;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			m[a[i]]=i;
			b[i-1]=a[i];
			if(max<a[i])
				max=a[i];
			if(min>a[i])
				min=a[i];
		}
		sort(b.begin(),b.end());
		while(q--) {
			int x;
			cin>>x;
			int mid=binary_search(a,b,n,x,max,min);
			//cout<<mid<<" ";
			if(m[x]==mid)
                cout<<ans<<"\n";
            else
                cout<<-1<<"\n";
		}
	}
	return 0;
}
