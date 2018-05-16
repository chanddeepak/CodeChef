#include<iostream>
#include<map>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        long a=0;
        map<long,int> m;
        for(int i=0;i<4;i++) {
        	cin>>a;
        	m[a]++;
        }
        map<long,int>:: iterator itr=m.begin(),itr2;
        itr2=itr++;
        if(m.size()==1) {
        	cout<<"YES\n";
        } else if(m.size()==2) {
        	if(itr->second==2&&itr2->second==2)
            cout<<"YES\n";
            else
            cout<<"NO\n";
        } else {
            cout<<"NO\n";
        }

    }
    return 0;
}
